
#include <stdlib.h>
#include <stdio.h>
#include "darray_generic.h"
typedef struct{
  int x;
  int y;
}point_t;
    
void destroyPoint(void *_elem, void *context);
void printPoint(void *_elem);
int  comparePoint(void *_elemA, void *_elemB);
void addItems(darray * ptr);
void removeItems(darray * ptr);
void setItem(darray * ptr);
 

int main(){
    FILE * fp;   
    darray * ptr;
    elementDestroy destroy=destroyPoint;
    elementPrint print=printPoint;
    elementCompare compare=comparePoint;
    int choose=0;
    size_t initial_capacity;
    fp=fopen("fileDet.txt","a");
    if(fp==NULL)
    {
        return 0;
    }

    printf("enter a capacity\n");
    scanf("%lu",&initial_capacity);
    darrayCreate(&ptr,initial_capacity);
    
    while(choose!=-1){
        printf("press 1 to add items\n");
        printf("press 2 to remove items\n");
        printf("press 3 to sort your items\n");
        printf("press 4 to set item\n");
        printf("press 5 to print your items\n");
        printf("press -1 to exit\n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                 addItems(ptr);
                 break;
            case 2:
                  removeItems(ptr);
                  break;
            case 3:
                 darraySort(ptr,compare);
                 break;
            case 4:
                setItem(ptr);
                break;
            case 5:
                printf("your array is: \n");
                printDarray(ptr,print);
                break;
            default: break;
    
        }
        

    }
    
    
    darrayDestroy(ptr,destroy,fp);
    fclose(fp);


    return 0;
}

void destroyPoint(void *_elem, void *context){
    FILE * fp=(FILE*)context;
    point_t * n=(point_t *)_elem;
    
         fprintf(fp," %d ",n->x);
         fprintf(fp," %d \n",n->y);
         free(n);
    
    
}

void printPoint(void *_elem)
{
    point_t * n=(point_t*)_elem;
    printf("%d ",n->x);
    printf("%d\n",n->y);
    
   
}


int  comparePoint(void *_elemA, void *_elemB){
   
    point_t * a=(point_t*)_elemA;
    point_t * b=(point_t*)_elemB;
    return ((a->x+a->y)-(b->x+b->y));
    
}




void addItems(darray * ptr){
    point_t * pointerAdd;
   pointerAdd=malloc(sizeof(point_t));
    while(pointerAdd->x!=-1){
       
       printf("enter x to add or -1 to stop\n");
       scanf("%d",&(pointerAdd->x));
       if(pointerAdd->x==-1){
        break;
       }
       printf("enter y to add or -1 to stop\n");
       scanf("%d",&(pointerAdd->y)); 
       darrayAdd(ptr,pointerAdd);
       pointerAdd=malloc(sizeof(point_t));
        
    
    }
}


void removeItems(darray * ptr){
    point_t* pointerRemove;
    int capacityRem,error;
    printf("enter the capacity of numbers to remove\n");
    scanf("%d",&capacityRem);
    while(capacityRem>0){
        pointerRemove=malloc(sizeof(point_t));
        error=darrayDelete(ptr, (void**)&pointerRemove);
        if(error==2){
            printf("cant remove your array is empty\n");
        }
        printf("%d ",pointerRemove->x);
        printf("%d \n",pointerRemove->y);
        capacityRem--;
        free(pointerRemove);
   }

}

    


    void setItem(darray * ptr){
        point_t * pointerAdd;
        size_t index;
        printf("enter a new points to change\n");
        pointerAdd=malloc(sizeof(point_t));
        printf("enter x to change\n");
        scanf("%d",&(pointerAdd->x));
        printf("enter y to change\n");
        scanf("%d",&(pointerAdd->y));
        printf("enter an index to change\n");
        scanf("%lu",&index);
        darraySet(ptr,index,pointerAdd);
    
        
    }