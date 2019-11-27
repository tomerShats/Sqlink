
#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for class_create */
#include <linux/slab.h> /* for kmalloc, kfree */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/sched.h> /* for TASK_INTERRUPTIBLE and more constants */
#include <linux/spinlock.h> /* for spinlock_t and ops on it */
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */
#include <linux/list.h>
#include "StructReg.h"
#define MAXINT 4096
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tomer Shats");
MODULE_DESCRIPTION("queues messages exercise");
MODULE_VERSION("1.12.44b");
static int pages_count = 8;
static dev_t first_dev;
struct node
{
	struct list_head node;
	char * data;
	int size;
};
struct messageQu
{
	struct list_head head;
    int size;
    int capacity;
    struct device *mq_device;
    wait_queue_head_t read_queue;
    struct mutex lock;
};
static struct messageQu * m_queues;
static int mq_open(struct inode *inode, struct file *filp)
{
	int the_page_number = iminor(inode)-MINOR(first_dev);
	struct messageQu *mq = m_queues+the_page_number;
	filp->private_data=mq;
	return 0;
}

static int list_has_data(struct messageQu * mq)
{
    int ret;
    mutex_lock(&mq->lock);
    ret=!list_empty(&mq->head);
    if(!ret) {
        mutex_unlock(&mq->lock);
    }
    return ret;
}

static long mq_ioctl(struct file *filp, unsigned int op,unsigned long buffer_usr)
{
	struct messageQu *mq = filp->private_data;
	int ret;
	char * buffer;
	struct mq_reg r;
	struct mq_reg * argp;
	struct node * node_new;
	int sizeR;	
    switch(op)
    {
		case MQ_SEND_MSG:
            argp=(struct mq_reg *)buffer_usr;
            ret=copy_from_user(&r,argp,sizeof(r));
            if(ret)
            {			     
                pr_err("error copy\n");
				return ret;
		    }
		    buffer=kmalloc(sizeof(char)*r.size, GFP_KERNEL);
            if (IS_ERR(buffer))
            {
                pr_err("error kmalloc\n");
                ret = PTR_ERR(buffer);
                return ret;
            } 	
            ret=copy_from_user(buffer,r.data,r.size);
            if(ret)
            {
                pr_err("error copy\n");
                return ret;
            }
            node_new=kmalloc(sizeof(struct node),GFP_KERNEL);
            if(IS_ERR(node_new))
            {
                pr_err("error kmalloc\n");
                ret=PTR_ERR(node_new);
                return ret;
            }				   
            node_new->data=buffer;
            node_new->size=r.size;
            ret=mutex_lock_interruptible(&mq->lock);
            if(ret)
            {
                pr_err("error mutex\n");
                return ret;
            }
            if(mq->size==100){
                mutex_unlock(&mq->lock);
                pr_err("the queue is full\n");
                kfree(node_new->data);
                kfree(node_new);
                /* find right error code for "out of space" */
                return -ENOTTY;
            }
            list_add(&(node_new->node),&(mq->head));
            mq->size++;
            mutex_unlock(&mq->lock);
            wake_up_interruptible(&mq->read_queue);				   
            return r.size;

		case MQ_RECV_MSG:
            ret=wait_event_interruptible(mq->read_queue, list_has_data(mq));
            if(ret==-ERESTARTSYS) {
                /* no need to release the mutex here */
                return ret;
            }
            node_new=list_entry((&mq->head)->prev, struct node, node);
            list_del((&mq->head)->prev);
            mq->size--;
            mutex_unlock(&mq->lock);
            sizeR=node_new->size;
            ret=copy_to_user((char*)buffer_usr,node_new->data,node_new->size);
            if(ret)
            {
                pr_err("%s: problem with copy_to_user\n", THIS_MODULE->name);
                return ret;
            }
            kfree(node_new->data);
            kfree(node_new);
            return sizeR;
           
		default:
                return -ENOTTY;	
	}
    return -ENOTTY;
}
static const struct file_operations pipe_fops =
{
	.owner = THIS_MODULE,
	.open=mq_open,
	.unlocked_ioctl = mq_ioctl,
};
static inline void mq_ctor(struct messageQu * m_queues)
{
	m_queues->size = 0;
	m_queues->capacity = 100;
	INIT_LIST_HEAD(&(m_queues->head));
	m_queues->mq_device=NULL;
    init_waitqueue_head(&m_queues->read_queue);
    mutex_init(&m_queues->lock);
}
static inline void mq_dtor(struct messageQu * m_queues)
{
     struct node * currentMsg;
     list_for_each_entry(currentMsg,&m_queues->head,node){
         kfree(currentMsg->data);
         kfree(currentMsg);
     }
     mutex_destroy(&m_queues->lock);
}
static struct class *my_class;
static struct cdev cdev;
static int first_minor;static int __init mq_init(void)
{
    int ret;
    int i;
    m_queues = kmalloc(sizeof(struct messageQu)*pages_count, GFP_KERNEL);
    if (IS_ERR(m_queues))
    {
		pr_err("error kmalloc\n");
		ret = PTR_ERR(m_queues);
		goto err_return;
	}    for (i = 0; i < pages_count; i++)
    {
         mq_ctor(m_queues+i);
    }    ret = alloc_chrdev_region(&first_dev, first_minor, pages_count,
			THIS_MODULE->name);
	if (ret)
    {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
    pr_debug("allocated the region\n");
    cdev_init(&cdev, &pipe_fops);
	ret = cdev_add(&cdev, first_dev, pages_count);
    if (ret)
    {
		pr_err("cannot cdev_add\n");
		goto err_dealloc;
	}    pr_debug("added the cdev\n");
    my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class))
    {
		pr_err("class_create\n");
		ret = PTR_ERR(my_class);
		goto err_cdev_del;
	}
    pr_debug("created the class\n");
	for (i = 0; i < pages_count; i++)
    {
		m_queues[i].mq_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+i),
			NULL, "%s%d", THIS_MODULE->name, i);
			if (IS_ERR(m_queues[i].mq_device))
            {
			pr_err("device_create\n");
			ret = PTR_ERR(m_queues[i].mq_device);
			goto err_class;
		    }
	}
	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;    err_class:
	class_destroy(my_class);
    err_cdev_del:
	cdev_del(&cdev);
    err_dealloc:
	unregister_chrdev_region(first_dev, pages_count);
    err_final:
	for (i = 0; i < pages_count; i++)
    {
        mq_dtor(m_queues+i);
    }	    
	kfree(m_queues);
    err_return:
	return ret;
}
static void __exit mq_exit(void)
{
	int i;	for (i = 0; i < pages_count; i++)
    {
		device_destroy(my_class, MKDEV(MAJOR(first_dev),
			MINOR(first_dev)+i));
    }	
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, pages_count);	
	for (i = 0; i < pages_count; i++)
    {
		mq_dtor(m_queues+i);
    }	
    kfree(m_queues);   
	
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}
module_init(mq_init);
module_exit(mq_exit);