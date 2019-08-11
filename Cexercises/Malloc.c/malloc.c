#include<stdio.h>
#include<stdlib.h>

int* insert (int,int*,int*,int*);

int main(){
     int capacity,count=0,num=0,i=0;
     int * p;
     printf("enter a capacity ");
     scanf("%d",&capacity);     
     p=(int*)malloc(capacity*sizeof(int));
     while(num!=-1){

        printf("enter a number ");
        scanf("%d",&num);
        if(num==-1){
            break;
        }
        p=insert(num,p,&count,&capacity);
        
        }
       for(i=0;i<capacity;i++){
            printf(" %d",p[i]);
       }
         free(p);
      return 0;   
     }

     int* insert (int num,int*p,int*count,int*capacity){
      int * temp=p;
      if((*count)<(*capacity)){

         p[(*count)]=num;
         (*count)++;
         

      }else{
        
        temp=(int *)realloc(p, sizeof(int)*((*capacity)+1)); 
           if(temp!=NULL){
              p=temp;
              p[(*count)]=num;
              (*count)++;
              (*capacity)++;
           }
           
      }
  

   return p;
}
