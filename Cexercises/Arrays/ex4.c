#include<stdio.h>
#define size 10
void sortEven(int * ,int);
int main(){
   int i=0;
   int s=10;
   int arr[size];
   
    for(i=0;i<size;i++)
    {
       printf("enter a number");
       scanf("%d",&arr[i]);
      

    }

   sortEven(arr,s);

 for(i=0;i<size;i++)
    {
       printf("%d",arr[i]); 

    }

return 0;
}


void sortEven(int * a ,int s){
   int i=0,j=0,temp,k;
    
        for(i=0;i<s;i++){
             j=i+1;
             if(a[i]%2==1){
                   
                  while((a[j]%2==1)&&(j<s)){
                    j++;
                  
                  }
                  
                  if(j<s){
                 for(k=j-1;k>=i;k--,j--){
                   temp=a[j];
                 a[j]=a[k];
                 a[k]=temp;

                  }
               }    

                 
               
                   

         }
      }
}

