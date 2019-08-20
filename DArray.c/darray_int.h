#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>

typedef enum {OK, AllocationError,WrongIndex} AdtStatus; 
/* forward declaration of the darray type */
typedef struct darray darray;
/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity);
AdtStatus darrayDestroy(darray *dArr);
AdtStatus printDarray(darray *dArr);
/* Add number to the end. */
AdtStatus   darrayAdd(darray *dArr,  int  _item);
/* Delete number from the end. */
AdtStatus   darrayDelete(darray *dArr,  int* _item);
AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item);
AdtStatus   darraySet(darray *dArr, size_t _index, int  _item);
AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems);
/* in place (ascending) sorting an array of size arraySize */
AdtStatus darraySort(darray *dArr);

#endif