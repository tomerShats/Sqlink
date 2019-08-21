#include <stdlib.h>
#include <stdio.h>
#include "darray_generic.h"


struct darray
{
   size_t initial_capacity;
   size_t capacity;
   size_t index;
   void ** arr;

};
static void quicksort(void ** arr,size_t first,size_t last,elementCompare compareFunc){
size_t i, j, pivot;
void * temp;
  if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while((compareFunc(arr[i],arr[pivot])<=0)&&i<last){
                 i++;
            }
                
            while((compareFunc(arr[j],arr[pivot])>0)){
                j--;
            } 
                
        if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1,compareFunc);
        quicksort(arr,j+1,last,compareFunc);
  }
}

AdtStatus printDarray(darray *dArr, elementPrint printFunc)
{   int i;
     if( (dArr)==NULL)
    {
        return   AllocationError;
        
    }

    for(i=0;i<dArr->index;i++)
    {
        printFunc(dArr->arr[i]);
    }
    printf("\n");
    return  OK;
}

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity){
     
      
     *dArr=malloc(sizeof(darray));
     if(*dArr==NULL){
        
         return AllocationError;
     }
     (*dArr)->arr=malloc(initial_capacity*sizeof(void*));
     if((*dArr)->arr==NULL){
         free(*dArr);
         return AllocationError;
     }
     (*dArr)->index=0;
     (*dArr)->capacity=initial_capacity;
     (*dArr)->initial_capacity=initial_capacity;
     return OK;
}


AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context){
    int i=0;
    if(dArr==NULL){
        return AllocationError;
    }
    for(i=0;i<dArr->index;i++){
        destroyFunc(dArr->arr[i],context);
    }
    free(dArr->arr);
    free(dArr);
    return OK;
}

AdtStatus   darrayAdd(darray *dArr,  void * _item){
    
    void ** temp;
    if(dArr==NULL){
        return AllocationError;
    }
   
    if(dArr->index==dArr->capacity){
        temp=realloc(dArr->arr,(dArr->capacity)*2*sizeof(void*));
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

AdtStatus   darrayDelete(darray *dArr,  void** _item){
    void ** temp;
    
    if(dArr==NULL){
        return AllocationError;
    }
    if(dArr->index==0){
        return WrongIndex;
    }
    dArr->index--;
    if((dArr->index==(size_t)(((dArr->capacity)/2)*(0.75)))&&((dArr->capacity)>(dArr->initial_capacity))){
        temp=realloc(dArr->arr,(dArr->capacity/2)*sizeof(void*));
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


AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item){
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

AdtStatus   darraySet(darray *dArr, size_t _index, void * _item){
    if(dArr==NULL){
        return AllocationError;
    }
    if(_index<=dArr->index){
        free(dArr->arr[_index]);
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
   return OK;

}

AdtStatus darraySort(darray *dArr,elementCompare compareFunc){
    size_t j=0;
     if(dArr==NULL){
        return AllocationError;
    }
    
    
       quicksort(dArr->arr,j,dArr->index-1,compareFunc); 
     return OK;
}