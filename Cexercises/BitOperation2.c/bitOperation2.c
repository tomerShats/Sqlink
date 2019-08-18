#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitOperation2.h"
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

int compress1(char* c){
   int i,count=1,size=0,size2;
   unsigned int num;
   
   
   if(c!=NULL){
      size=strlen(c);
      
      c[0]=c[0]-'a';
      c[0]=c[0]<<4;
   
     
       for(i=1;i<size;i++){
            if(i%2==1){
                c[i]=c[i]-'a';
                c[i-count]=c[i-count]|c[i];
                c[i]=c[i]<<8;
            }else{
               c[i]=c[i]-'a';
               c[i-count]=c[i-count]|c[i];
               c[i-count]=c[i-count]<<4;
               c[i]=c[i]<<8;
               count++;
           
            }
       }
       
     size2=(size%2==0)?size/2:size/2+1;
     for(i=0; i<size2;i++){
        num=(unsigned int)(c[i]);
        toBinari(num);
     }
     return size;
   }
  return size;
}


int compress2(char* c){
   int i,count=1,size=0,size2,j=0;
   unsigned int num;
   un uni;
   
   if(c!=NULL){
      size=strlen(c);
     
       for(i=0,j=0;i<size;i++,j+=2){
         uni.lr.left=(c[j]-'a');
         if((j+1)>=size){
             uni.lr.right=0;
             c[i]=uni.c;
             break;
         }
         uni.lr.right=(c[j+1]-'a');
         c[i]=uni.c;
                
       }
       
     size2=(size%2==0)?size/2:size/2+1;
     for(i=0; i<size2;i++){
        num=(unsigned int)(c[i]);
        toBinari(num);
     }
      
     return size;
   }
  return size;
}




















