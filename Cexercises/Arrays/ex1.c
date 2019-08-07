#include<stdio.h>
#define size 10
void sort(int * ,int);
int main(){
   int i=0;
   int s=10;
   int arr[size];
   
    for(i=0;i<size;i++)
    {
       printf("enter a number");
       scanf("%d",&arr[i]);
      

    }

   sort(arr,s);

 for(i=0;i<size;i++)
    {
       printf("%d",arr[i]); 

    }

return 0;
}


void sort(int * a ,int s){
   int i=0,j=0,swap=1,temp;
    while(swap==1){
         swap=0;
        for(i=0;i<s-1;i++){
             if(a[i]>a[i+1]){
                temp=a[i];
                 a[i]=a[i+1];
                 a[i+1]=temp;
                 swap=1;
                 
             }      

         }
      }
}

