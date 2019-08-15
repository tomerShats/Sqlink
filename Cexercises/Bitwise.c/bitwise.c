#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitwise.h"

static void toBinari(int v){
       char a[256];
       int i=0,j=0;
     
       
       while(v>0){
        a[i]=v%2+'0';
         v=v/2;
         i++;
         
       } 
    a[i]='\0';
         
         for(i=32;i>=0;i--){
            if(i<=strlen(a)){
              printf("%c",a[i]);
            }else{
              printf("%c",'0');
            }
         }
        
}

bitMap_t* createBitMap(int nf){
  bitMap_t* bm;
  int size,i;
  bm=malloc(sizeof(bitMap_t));
   if(bm==NULL){
       return NULL;
   }
  size=(nf%32>0)?(nf/32+1):(nf/32);
  bm->m_bitArr=calloc(size,sizeof(unsigned int));
  
   if(bm->m_bitArr==NULL){
         free(bm);
         return NULL;
   }
    bm->m_nf=nf;
	   
 return bm;
  
}

int bitOn(bitMap_t*bm,int n){
  unsigned int num=1;
  int indexNum,indexBinary;
  if(n>(bm->m_nf)){
      return -1;
  }
  if(n%32==0){
     indexNum=n/32-1;
  }else{
     indexNum=n/32;
  }
  indexBinary=(n%32==0)?32:n%32;
  num=num<<(indexBinary-1);
  bm->m_bitArr[indexNum]=bm->m_bitArr[indexNum]|num;
  
  return 1;
  
}

int bitOff(bitMap_t*bm,int n){
  unsigned int num=1;
  int indexNum,indexBinary;
  if(n>(bm->m_nf)){
      return -1;
  }
  indexNum=(n%32==0)?(n/32)-1:(n/32);
  indexBinary=(n%32==0)?32:n%32;
  num=num<<indexBinary-1;
  num=~num;
  bm->m_bitArr[indexNum]=bm->m_bitArr[indexNum]&num;
  return 1;
}
int bitStatus(bitMap_t*bm,int n){
  unsigned int num=1;
  int indexNum,indexBinary;
  if(n>(bm->m_nf)){
      return -1;
  }
  indexNum=(n%32==0)?(n/32)-1:(n/32);
  indexBinary=(n%32==0)?32:n%32;
  num=num<<indexBinary-1;
  num=bm->m_bitArr[indexNum]&num;
  if(num!=0){
     return 1;
  }else{
   return 0;
  }
  
}

void printBitMap(bitMap_t*bm){
  int i=0,size;
  unsigned int num;
  if(bm!=NULL){
     size=(bm->m_nf%32>0)?(bm->m_nf/32+1):(bm->m_nf/32);
     for(i=size-1; i>=0;i--){
        num=(bm->m_bitArr[i]);
        toBinari(num);
     }
  }

}


void destroy(bitMap_t*bm){
 if(bm!=NULL){
       free(bm->m_bitArr);
       free(bm);
    
 }
}
