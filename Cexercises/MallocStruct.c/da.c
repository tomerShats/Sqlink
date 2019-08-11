#include <stdio.h>
#include <stdlib.h>
#include "da.h"



Da_t * create(int capacity){

	   Da_t * da;
           da=malloc(sizeof(Da_t));
           da->capacity=capacity;
	   da->count=0;
           da->arr=malloc(sizeof(int)*capacity);
           
	   

    return da;
}



int insert(Da_t* da,int num){
  
  int * temp=da->arr;
      if((da->count)==(da->capacity)){
          temp=(int *)realloc(da->arr, sizeof(int)*((da->capacity)*2)); 
           if(temp!=NULL){
             da->arr=temp;
             (da->capacity)*=2;
           }else{
               return 0;
           
           }
     
           
      }
       da->arr[da->count]=num;
       (da->count)++;
  
    return 1;

}



void print(Da_t* da){
   int i=0;
   for(i=0;i<da->count;i++){
      printf(" %d",da->arr[i]);
   }


}



void destroy(Da_t* da){
  free(da->arr);
  free(da);

}




















