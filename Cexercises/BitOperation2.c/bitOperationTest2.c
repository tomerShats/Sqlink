#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitOperation2.h"




int main(){
  char c[512];
  int sizeOriginal,choose=0;
  while(choose!=-1){
    printf("enter a string \n");
    scanf("%s",c);
    printf("press 1 for compress without bit field \n");
    printf("press 2 for compress with bit field and union \n");
    printf("press -1 for compress with bit field and union \n");
    scanf("%d",&choose);
       switch(choose){
           case 1:
              sizeOriginal=compress1(c);
              printf("\n");
              printf("%d the original size\n",sizeOriginal);
              break;
           case 2:
              sizeOriginal=compress2(c);
              printf("\n");
              printf("%d the original size\n",sizeOriginal);
              break;
           default: break;
       
        }
     
  }
  
return 0;
}
