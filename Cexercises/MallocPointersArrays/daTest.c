#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "da.h"




int main(){
     int capacity=0;
     int * num;
     int error=1;
     Da_t * da;
     printf("enter a capacity\n");
     scanf("%d",&capacity);
     da=create(capacity);
     while((*num)!=-1){
           num=malloc(sizeof(int));
	   if(num!=NULL){
		   printf("enter a number ");
		   scanf("%d",num);
		   if((*num)==-1){
		     break;
		   }
		   error=insert(da,num);
		   if(error==0){
		      printf("the realloc was unsuccessful");
		       break;
		   
		   }
	   }
        
    }
     print(da);
     destroy(da);
   
        
      return 0; 



}
