
#include <stdlib.h>
#include <stdio.h>
#include "memManage.h"

char buffer [40];
int main(){
char * n;
char * n1;
char * n2;
char * n3;
int * p;
int size=8,i=0;
int sizeBig=40;
n= (char*)memInit(buffer,&sizeBig);
p=(int*)&n[0];
n1=(char *)memAlloc(n,sizeBig,size);
n2=(char *)memAlloc(n,sizeBig,size-4);
n3=(char *)memAlloc(n,sizeBig,size);
for(i=0;i<sizeBig/4;i++){
    printf("%d ",p[i]);
}
memFree(n1,buffer,sizeBig);
    return 0;
}
