#include<stdio.h>
#define size 10
void sort01(int * ,int);
int main(){
   int i=0;
   int s=10;
   int arr[size];
   
    for(i=0;i<size;i++)
    {
       printf("enter 0 or 1");
       scanf("%d",&arr[i]);
      

    }

sort01(arr,s);

 for(i=0;i<size;i++)
    {
       printf("%d",arr[i]); 

    }

return 0;
}


void sort01(int * a ,int s){
   int i=0,j=0;

   for(i=0;i<s;i++){
      if(a[i]==1){
         j=i+1;
         while((j<s)&&(a[j]==1)){
            j++;
         }
        if(s>j){
          a[i]=a[j];
          a[j]=1;
       
        } 
       }

    }
}
