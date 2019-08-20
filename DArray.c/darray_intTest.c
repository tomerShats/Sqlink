#include <stdlib.h>
#include <stdio.h>
#include "darray_int.h"


int main(){

darray * ptr;
int numRemove,numAdd=0,capacityRem,error;
size_t initial_capacity,index;
printf("enter a capacity\n");
scanf("%lu",&initial_capacity);
darrayCreate(&ptr,initial_capacity);
while(numAdd!=-1){
   printf("enter a num to add or -1 to stop\n");
   scanf("%d",&numAdd);
   if(numAdd==-1){
       break;
   }
   darrayAdd(ptr,numAdd);
    
}
printf("your array is: \n");
printDarray(ptr);
printf("your array after sort: \n");
darraySort(ptr);
printDarray(ptr);
printf("enter a num to change\n");
scanf("%d",&numAdd);
printf("enter an index to change\n");
scanf("%lu",&index);
darraySet(ptr,index,numAdd);
printf("your array after change\n");
printDarray(ptr);
printf("enter the capacity of numbers to remove\n");
scanf("%d",&capacityRem);
while(capacityRem>0){
   error=darrayDelete(ptr, &numRemove);
   if(error==2){
       printf("cant remove your array is empty\n");
   }
   printf("%d \n",numRemove);
   capacityRem--;
}
printf("your array after the remove:  \n");
printDarray(ptr);




darrayDestroy(ptr);



    return 0;
}