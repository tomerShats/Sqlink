#include <stdlib.h>
#include <stdio.h>
#include "memManage.h"
static int setFree(int  p){
   
    return p&0x7fffffff;

}
static int setOcc(int  p){
   
    return p|0x80000000;

}

static int isReady(int * p){
   
    int temp=1;
    temp=temp<<31;
    temp=temp&*p;
    return temp;


}

static int * split(int * p,int sizeSmall){
     int size=*p;
      *p=sizeSmall+4;
      *(p+(sizeSmall/4+1))=size-sizeSmall-4;
      *p=setOcc(*p);
      *(p+(sizeSmall/4+1))=setFree(*(p+(sizeSmall/4+1)));
      return p+1;
     

 }

void * memInit(char * buffer,int * size){
   int * p;
   
  if((size_t)buffer%4!=0){
      *size=*size-(4-(size_t)buffer%4);
      buffer=buffer+(4-(size_t)buffer%4);
      
  }  
  if((size_t)(buffer+*size-1)%4!=0){
      *size=*size-((size_t)(buffer+*size-1)%4)-1;
      
  }
   p=(int*)&buffer[0];
   *p=*size;
   *p=setFree(*p);
  return buffer;

}


void * memAlloc(char * buffer,int sizeBig,int sizeSmall){
  int i=0,j=0;
    int * p;
    
   if(sizeSmall%4!=0){
      sizeSmall=sizeSmall+(4-sizeSmall%4);
   
   }
    p=(int *)&buffer[0];
    
  
   for(i=0;i<sizeBig/4;){
       
       if(isReady(p+i)==0){
            if(p[i]>sizeSmall+4){
                 p=split(&p[i],sizeSmall);
                return p;
            }else if(p[i]-4==sizeSmall){
                      p[i]=setOcc(p[i]);
                     return &p[i+1];
            }else{
                i=i+(p[i]/4);

            }
       }else{
            p[i]=setFree(p[i]);
            j=i;
             i=i+(p[i]/4);
             p[j]=setOcc(p[j]);
            
       }
   }
   return NULL;   


}

void  memFree(char * pFree,char * buffer,int size){
   
   int * p;
   int * temp;
   p=(int *)&pFree[0]-1;
   *p=setFree(*p);
   
}
