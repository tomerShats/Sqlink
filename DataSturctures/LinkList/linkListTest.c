#include <stdio.h>
#include <stdlib.h>


struct node{
  int num;
  struct node * next;
};


typedef struct node node;
node * flip(node * head);
node * makeList(int size);
void printList(node * head);
node* middleNode(node * head);
int isLoop(node * head);
node * comminNode(node * head1,node * head2);
int getCount(node* head);
void destroyList(node * head);


int main(){
    node * ptr1;
    node * ptr2;
    node * ptr3;
    node * middle1;
    node * middle2;
    int size,loop;
    printf("enter size\n");
    scanf("%d",&size);
    ptr1=makeList(size);
    printList(ptr1);
    ptr1=flip(ptr1);
    printf("after flip function:\n");
    printList(ptr1);
    printf("enter size\n");
    scanf("%d",&size);
    ptr2=makeList(size);
    printList(ptr2);
    middle1=middleNode(ptr1);
    printf("the middle of list1 is: %d \n",middle1->num);
    middle2=middleNode(ptr2);
    middle1->next=middle2;
    ptr3=comminNode(ptr1,ptr2);
    if(ptr3==NULL){
        printf("there isnt like that\n");
    }
    printf(" the common node is %d: \n",ptr3->num);
    loop=isLoop(ptr2);
    if(loop==1){
       printf("there is a loop in list 2 \n");
    }else{
        printf("there is not any loop list 2 \n");
    }
    
destroyList(ptr1);
destroyList(ptr2);

  return 0;
}

void destroyList(node * head){
    node * current=head;
    while(current!=NULL){
        current=current->next;
        free(head);
        head=current;
    }
}

void printList(node * head){
    node * current =head;
    if(isLoop(head)==0){
        while(current!=NULL){
            printf("%d ",current->num);
            current=current->next;
        }
    printf("\n");
    }
}
node * makeList(int size){
    int i=0;
    node * head=NULL;
    node * current=NULL;
    
    if(size==0){
        return NULL;
    }
    head=malloc(sizeof(node));
    head->num=i;
    head->next=NULL;
    current=head;
    for(i=1;i<size;i++){
       current->next=malloc(sizeof(node));
       current=current->next;
       current->num=i;
       
    }
    current->next=NULL;
    return head;
}

node * flip(node * head){
    node * current=head;
    node * prev=NULL;
    node * nextN=NULL;
    while(current!=NULL){
        nextN=current->next;
        current->next=prev;
        prev=current;
        current=nextN;

    }
 head=prev;
 return head;
}


node * middleNode(node * head){
    node * current1=head;
    node * current2=head;
    if(head==NULL){
        return NULL;
    }
    while((current2!=NULL)&&(current2->next!=NULL)){
        current1=current1->next;
        current2=current2->next;
        current2=current2->next;
    
    }
    return current1;
}


int isLoop(node * head){
    node * current1=head;
    node * current2=head;
    if(head==NULL){
        return -1;
    }
    while((current2!=NULL)&&(current2->next!=NULL)){
        current1=current1->next;
        current2=current2->next;
        current2=current2->next;
        if(current1==current2){
            return 1;
        }
    
    }
    return 0;
}
int getCount(node* head) 
{ 
    node* current = head; 
    int count = 0; 
  
    while (current != NULL) { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 


node * comminNode(node * head1,node * head2){
   int i,d,flag=0; 
    node * current1 = head1; 
    node * current2 = head2; 
    d=getCount(head1)-getCount(head2);
    if(d<0){
        d=(-1)*d;
        flag=1;
    }
   if(flag==1){
      for (i = 0; i<d; i++) { 
        if (current2 == NULL) { 
            return NULL; 
        }
        
           current2=current2->next; 
        
      }
   }else{
       for (i = 0; i<d; i++) { 
        if (current1 == NULL) { 
            return NULL; 
        }
            current1=current1->next;
        
    }
   }
      
    while (current1 != NULL && current2 != NULL) { 
        printf("%d \n",current1->num);
        if (current1 == current2) 
            return current1; 
        current1 = current1->next; 
        current2 = current2->next; 
    } 
    return NULL; 
}