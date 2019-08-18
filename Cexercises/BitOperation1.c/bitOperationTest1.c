#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitOperation1.h"

int main(){
  unsigned char x,y;
  int n,p,value=0,choose=0,error,i,j;
  while(choose!=-1){
     printf("press 1 for comliment\n");
     printf("press 2 for rotates\n");
     printf("press 3 for setBits\n");
     printf("press 4 for setBits2\n");
     printf("press -1 for exit\n");
     scanf("%d",&choose);
     switch(choose){
      case 1:
         x=170;
         error=comliment(&x);
         if(error==0){
             printf("error\n");

         }
           break;
       case 2:
           x=170;
           printf("enter a n bits to shift right\n");
           scanf("%d",&n);
           error=rotates(&x,n);
           if(error==0){
             printf("error\n");

           }
           break;
        case 3: 
               x=170;
               y=167;
               printf("enter a n bits to move\n");
               scanf("%d",&n);
               printf("enter a p bits to put the bits\n");
               scanf("%d",&p);
               error=setBits(&x,p,n,&y);
               if(error==0){
               printf("error\n");

               }
            break;
        case 4:
               x=170;
               printf("enter i location\n");
               scanf("%d",&i);
               printf("enter j location\n");
               scanf("%d",&j);
               printf("enter value 0 or 1\n");
               scanf("%d",&value);
               error=setBits2(&x,i,j,value);
               if(error==0){
               printf("error\n");

               }
               break;
         default: break;
 
         
       }

     

  }
  

return 0;
}
