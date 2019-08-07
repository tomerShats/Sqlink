#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void lotto(int*,int);


int main(){
    int a[6],i,j,row,col,flag=0,size=6;
      srand(time(NULL));
       
      a[0]=rand()%49+1;
        printf("%d\n",a[0]);
     
     srand(time(0));
 for(i=1;i<6;i++){
          
          do{
          flag=0;
         
         a[i]=rand()%49+1;
             for(j=0;j<i;j++){
                if(a[i]==a[j]){
                 a[i]=rand()%49+1;
                 flag=1;
                 }
              }
           }while(flag==1);
          printf("%d\n",a[i]);
         

        }
        lotto(a,size);


return 0;
}




void lotto(int * a,int size){
int i,j,row,col;
 char lotto[5][10];
   
for(row=0;row<5;row++){
             for(col=0;col<10;col++){
                lotto[row][col]='-';

             }

          }

       for(i=0;i<6;i++){
         if(a[i]<10){
            lotto[0][a[i]-1]='+';
          }else if(a[i]%10==0){
              row=(a[i]/10)%10-1;
             lotto[row][9]='+';
              
           }else{
              col=a[i]%10-1;  
              row=(a[i]/10)%10;
              lotto[row][col]='+';

           }
        

        }
printf(" 1 2 3 4 5 6 7 8 9 10\n");
  for(row=0;row<5;row++){
          printf("%d ",row);
             for(col=0;col<10;col++){
                printf("%c ",lotto[row][col]);

             }
          printf("\n");
          }


}
