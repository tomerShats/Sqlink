#include<stdio.h>


void func1(int num){
   int row,col;
    for(row=0;row<num;row++){
     
     for(col=0;col<=row;col++){
      printf("*");
  }
       printf("\n");
  }

}
void func2(int num){
   int row,col;
        for(row=0;row<num;row++){
    
        for(col=0;col<=row;col++){
         printf("*");
     }
     printf("\n");
      }
        for(row=num-1;row>0;row--){
    
        for(col=num-1;col>num-1-row;col--){
        printf("*");
      }
      printf("\n");
     }

}

void func3(int num){
   int row,col,i,j=0;
        for(i=0,row=0;row<num;i=i+2,row++){
         j=row;
    
           for(col=0;col<=i;col++){
                while(j<num){
                    printf(" ");
                      j++;
                     }
                 printf("*");

             }
        printf("\n");
     }
 

}



int main(){
int n;
printf("enter a number");
scanf("%d",&n);
func1(n);
printf("\n");
func2(n);
printf("\n");
func3(n);
return 0;

}

