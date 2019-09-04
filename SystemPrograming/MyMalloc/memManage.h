#ifndef H_DARRAY
#define H_DARRAY
#include <stdlib.h>

void * memInit(char * buffer,int *size);
void * memAlloc(char * buffer,int sizeBig,int sizeSmall);
void  memFree(char * pFree,char* buffer,int size);

#endif