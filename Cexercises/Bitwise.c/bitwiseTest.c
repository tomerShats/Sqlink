#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitwise.h"


int main(){
   unsigned int nf,n,error;
   int funcNum;
   bitMap_t*bm;
   bitFunc bf[3]={bitOn,bitOff,bitStatus};
   printf("enter numbers of bits \n");
   scanf("%u",&nf);
   bm=createBitMap(nf);
   do{
     printf("enter the bit you want \n");
     scanf("%u",&n);
     printf("press 0 for bitOn \n");
     printf("press 1 for bitOff \n");
     printf("press 2 for bitStatus \n");
     printf("press -1 for exit \n");
     
     scanf("%d",&funcNum);
     error=bf[funcNum](bm,n);
     if(error==-1)
      {
         printf("cant work \n");
      }else if((error==1)&&(funcNum==2)){
           printf("the bit is on \n");
      }else if(error==0){
        printf("the bit is off \n");
      }
      
     printBitMap(bm);
    }while(funcNum!=-1);

   return 0;
   

}
