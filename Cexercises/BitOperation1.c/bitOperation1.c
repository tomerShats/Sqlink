#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "bitOperation1.h"

static void toBinari(unsigned int v){
       char a[256];
       int i=0,j=0;
    
       while(v>0){
        a[i]=v%2+'0';
         v=v/2;
         i++;
         
       } 
    a[i]='\0';
         
         for(i=8;i>=0;i--){
            if(i<=strlen(a)){
              printf("%c",a[i]);
            }else{
              printf("%c",'0');
            }
         }
        
}

int comliment(unsigned char* c){
   
   unsigned int num;
   unsigned char temp=0;
   
   
   
   if(c!=NULL){
       
      temp=~temp;
      *c=*c^temp;
     
     
        num=(unsigned int)(*c);
        toBinari(num);
    
     return 1;
   }
  return 0;
}

int rotates(unsigned char* c,int n){
   
   unsigned int num;
   unsigned char temp=0;
   
   if(c!=NULL){
       
      temp=*c;
      temp=temp<<(8-n);
      *c=*c>>n;
      *c=*c|temp;
     
        num=(unsigned int)(*c);
        toBinari(num);
    
     return 1;
   }
  return 0;
}


int setBits(unsigned char* x,int p,int n,unsigned char* y){
   unsigned int num;
   unsigned char temp=pow(2,n)-1;
    if((x!=NULL)&&(y!=NULL)){
       
      temp=temp<<(p-n);
      temp=~temp;
      *x=*x&temp;
      *y=*y<<(8-n);
      *y=*y>>(8-p);
      *x=*y|*x;
     
        num=(unsigned int)(*x);
        toBinari(num);
    
     return 1;
   }
  return 0;
   
}

int setBits2(unsigned char* x,int i,int j,int value){
   unsigned int num;
   unsigned char temp=pow(2,j-i+1)-1;
    if(x!=NULL){
       temp=temp<<(i-1);
       if(value==1){
          *x=*x|temp;
       }else{
          temp=~temp;
          *x=*x&temp;
       }
       num=(unsigned int)(*x);
        toBinari(num);
        return 1;
    }
   return 0;
}













