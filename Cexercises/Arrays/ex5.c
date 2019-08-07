#include<stdio.h>
#define size 10
int max(int * ,int);
int main(){
   int i=0;
   int s=10;
   int arr[size];
   
    for(i=0;i<size;i++)
    {
       printf("enter a number");
       scanf("%d",&arr[i]);
      

    }

   printf("%d",max(arr,s));



return 0;
}


int max(int * a ,int s){
 int max=0,i,j,count=0,maxNum=a[0];
        for(i=0;i<s;i++){        
           for(j=0;j<s;j++){  
           if(a[i]==a[j]){
            count++;
            }      
             
          
         }
         if(max<count){
             max=count;
             maxNum=a[i];
              }     
          count=0;
         }

return maxNum;
}


