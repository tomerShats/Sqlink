#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "files.h"


int main(){ 
  char name [100];
  int n,choose=0;
   while(choose!=-1){
        printf("\n");
        printf("press 1 for lastNlines \n");
        printf("press 2 for countWord \n");
        printf("press 3 for countChar \n");
        printf("press -1 for printf \n");
        scanf("%d",&choose);
        switch(choose){
            case 1:
                  printf("enter your file name ");
                  scanf("%s",name);
                  printf("enter N lastlines ");
                  scanf("%d",&n);
                  lastNlines(n,name);
  
                  break;
            case 2:
                   printf("enter your file name ");
                  scanf("%s",name);
                  countWord(name);
 
                 break;
            case 3:
                  printf("enter your file name ");
                  scanf("%s",name);
                  countChar(name);
                  break;
            default: break;
         }
     }


 return 0;
}
