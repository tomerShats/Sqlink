#include <stdlib.h>
#include <stdio.h>
#include "darray_int.h"


struct darray
{
   size_t initial_capacity;
   size_t capacity;
   size_t index;
   int * arr;

};

AdtStatus printDarray(darray *dArr)
{   int i;
     if( (dArr)==NULL)
    {
        return   AllocationError;
        
    }  
    for(i=0;i<dArr->index;i++)
    {
        printf("%d ",dArr->arr[i]);
    }
    printf("\n");
    return  OK;
}


AdtStatus darrayCreate(darray **dArr, size_t initial_capacity){
     
      
     *dArr=malloc(sizeof(darray));
     if(*dArr==NULL){
        
         return AllocationError;
     }
     (*dArr)->arr=malloc(initial_capacity*sizeof(int));
     if((*dArr)->arr==NULL){
         free(*dArr);
         return AllocationError;
     }
     (*dArr)->index=0;
     (*dArr)->capacity=initial_capacity;
     (*dArr)->initial_capacity=initial_capacity;
     return OK;
}


AdtStatus darrayDestroy(darray *dArr){
    if(dArr==NULL){
        return AllocationError;
    }
    free(dArr->arr);
    free(dArr);
    return OK;
}

AdtStatus   darrayAdd(darray *dArr,  int  _item){
    
    int * temp;
    if(dArr==NULL){
        return AllocationError;
    }
    if(dArr->index==dArr->capacity){
        temp=realloc(dArr->arr,(dArr->capacity)*2*sizeof(int));
        if(temp!=NULL){
            dArr->arr=temp;
            dArr->capacity=dArr->capacity*2;
        }else{
            return AllocationError;
            
        }
    }
    dArr->arr[dArr->index]=_item;
    dArr->index++;
    return OK;
    
}

AdtStatus   darrayDelete(darray *dArr,  int* _item){
    int * temp;
    
    if(dArr==NULL){
        return AllocationError;
    }
    if(dArr->index==0){
        return WrongIndex;
    }
    dArr->index--;
    if((dArr->index==(size_t)(((dArr->capacity)/2)*(0.75)))&&((dArr->capacity)>(dArr->initial_capacity))){
        temp=realloc(dArr->arr,(dArr->capacity/2)*sizeof(int));
        if(temp!=NULL){
            dArr->arr=temp;
            dArr->capacity=dArr->capacity/2;
        }else{
            return AllocationError;
            
        }
    }
    *_item=dArr->arr[dArr->index];
    return OK;
}


AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item){
    if(dArr==NULL){
        return AllocationError;
    }
    if(_index<=dArr->index){
       *_item=dArr->arr[_index];
        return OK;
    }else{
       return WrongIndex;
    }
    
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item){
    if(dArr==NULL){
        return AllocationError;
    }
    if(_index<=dArr->index){
       dArr->arr[_index]=_item;
        return OK;
    }else{
       return WrongIndex;
    }
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems){
    if(dArr==NULL){
        return AllocationError;
    }
   * _numOfItems=dArr->index;

}

AdtStatus darraySort(darray *dArr){
    int i,temp,swap=0,j=0;
     if(dArr==NULL){
        return AllocationError;
    }
    for(i=0;i<dArr->index-1;i++){
         swap=0;
        for(j=0;j<dArr->index-1;j++){
            if(dArr->arr[j]>dArr->arr[j+1]){
            temp=dArr->arr[j];
            dArr->arr[j]=dArr->arr[j+1];
            dArr->arr[j+1]=temp;
            swap=1;
            }
      
        } 
          if(swap==0){
           break;
      
         }  
        
    }

     return OK;
}