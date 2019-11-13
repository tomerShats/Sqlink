#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/stat.h> /* for permission bits on module_param */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for device_create */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC... */
#include <linux/init.h>
#include <linux/cdev.h> /* for __init, __exit */
#include <linux/uaccess.h>
static dev_t mhnull_dev_number;
static struct class *mhnull_class;
static struct device *mhnull_dev;
static struct cdev driver_object;

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tomer shats");
MODULE_DESCRIPTION("dev null driver");
MODULE_VERSION("1.0.0");
static int driver_open(struct inode *device, struct file *instanz)
	{
		dev_info(mhnull_dev, "mhnull driver loaded\n");
		return 0;
	}
	static int driver_close (struct inode *device, struct file *instanz)
	{
		dev_info(mhnull_dev, "mhnull driver closed\n");
		return 0;
	}
	static ssize_t driver_write(struct file *instanz, const char __user *user, size_t count, loff_t *offset)
	{
		*offset += count;
		return count;
	}
	static struct file_operations fops = {
			.owner = THIS_MODULE,
			.open = driver_open,
			.write  = driver_write,
			.release = driver_close,
	};
static int __init mod_init(void)
{
	int error_value;
	pr_info("mhnull: mod_init\n");
	error_value = alloc_chrdev_region(&mhnull_dev_number, 0, 1, THIS_MODULE->name);
	if(error_value<0) {
		pr_err("mhnull: could not allocate a chardev region\n");
		goto err_nothing;
	}
        cdev_init(&driver_object, &fops);
       if (cdev_add(&driver_object, mhnull_dev_number, 1))
		goto err_release_chardev;
        
        mhnull_class=class_create(THIS_MODULE, THIS_MODULE->name);
        if (IS_ERR(mhnull_class)){
                pr_err("mhnull: no udev support\n");
		error_value=PTR_ERR(mhnull_class);
		goto err_release_chardev;
        }

        mhnull_dev = device_create(mhnull_class, NULL, mhnull_dev_number, NULL, "%s",THIS_MODULE->name);
	if (IS_ERR(mhnull_dev)) {
		pr_err("mhnull:device create failed\n");
                error_value=PTR_ERR(mhnull_dev);
		goto err_free_class;
	}
        
        
        pr_info("mhnull: the init is good\n");
           
        
	return 0;
      
        err_free_class:
                 class_destroy(mhnull_class);
	err_release_chardev:
		unregister_chrdev_region(mhnull_dev_number, 1);
	err_nothing:
		return error_value;
}


static void __exit mod_exit(void)
{
	pr_info("mhnull: mod_exit\n");
        device_destroy(mhnull_class, mhnull_dev_number);
        cdev_del(&driver_object);
        class_destroy(mhnull_class);
        unregister_chrdev_region(mhnull_dev_number, 1);
        
}

module_init(mod_init);
module_exit(mod_exit);
