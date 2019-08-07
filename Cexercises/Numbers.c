#include<stdio.h>

int polindrome (int num){

     int test=num;
     int numRev=0;
         while(test>0){
           numRev=numRev*10+test%10;
           test=test/10;

         }
    if(num==numRev){
      
      return 1;
     
    }else{
      
      return 0;
    }  


}

int ascending (int num){

    int d1=num%10;
    int d2;
         while(num>10){
          num=num/10;
          d2=num%10;
             if(d1<d2){

              return 0;
             }
         d1=d2;

         }
       return 1;
}
int perfect (int num){

    int sum=0,i=1;;
    
         while(i<=num/2+1){
             if(num%i==0){

              sum=sum+i;
             }
         i++;

         }
             if(num==sum){

             return 1;
             }else{
              
             return 0;
   
             }
         
       
}
int reverse (int num){

   
          int numRev=0;
         while(num>0){
           numRev=numRev*10+num%10;
           num=num/10;

         }
     return numRev;
    
       
}
int prime (int num){

   
          int i=3;
         while(i<num/2+1){
          if(num%i==0){

              return 0;
             }
         i++;
          
         }
     
     return 1;  
}

int main(){
int n;
printf("enter a number for prime\n");
scanf("%d",&n);
printf("%d\n",prime(n));

printf("enter a number to reverse\n");
scanf("%d",&n);
printf("%d\n",reverse(n));

printf("enter a number for perfect\n");
scanf("%d",&n);
printf("%d\n",perfect(n));

printf("enter a number for ascending");
scanf("%d",&n);
printf("%d\n",ascending(n));

printf("enter a number for polindrome");
scanf("%d",&n);
printf("%d\n",polindrome(n));
return 0;

}

