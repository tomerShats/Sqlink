#include<stdio.h>
#include<string.h>

void toBinari(int);
void toDecimal(char*);
int decimalBinaryMain();
int locationMain();
int location(char*,char*);
int squeezeMain();
void squeeze(char*,char*);




int main(){
      	
      int opt;

      printf("enter 1 for decimalBinaryMain \n");
      printf("enter 2 for locationMain \n");
      printf("enter 3 for squeezeMain() \n");
      

      scanf("%d",&opt);
      
      switch(opt){
            
             case 1:
                    decimalBinaryMain();  break;

             case 2: 
                    locationMain();    break;
             case 3:
                    squeezeMain();     break; 

             default:  break;
              
              }
    
    return 0;
}


int squeezeMain(){
     char a[100];
    char b[100];
    printf("enter a string ");
    scanf("%s",a);
    printf("enter a string ");
    scanf("%s",b);
    squeeze(a,b);
    printf(" %s " ,a);   
    
    
    
return 0;

}



void squeeze(char*a,char*b){
        
     int i=0,j=0,temp,inedxSwap=0;;
     for(i=0;i<strlen(b);i++)
        {
             for(j=0;j<strlen(a);j++)
             {
                 if(a[j]==b[i]){
                      inedxSwap=j;

                     while((a[inedxSwap]!='\0')&&(a[inedxSwap+1]!='\0')){
                      temp=a[inedxSwap];
                      a[inedxSwap]=a[inedxSwap+1];
                      a[inedxSwap+1]=temp;
                      inedxSwap++;
                          
                     }
                     a[inedxSwap]='\0';
                     j--;

                 }

             }
        }
}

int locationMain(){
    
    char a[100];
    char b[100];
    printf("enter a string ");
    scanf("%s",a);
    printf("enter a string ");
    scanf("%s",b);
    printf(" %d ",location(a,b));   
    
    


  return 0;
}


int location(char*a,char*b){
   int i,j,indexB,location=-1;
       for(i=0;i<strlen(a);i++){
              indexB=0;
              if (a[i]==b[indexB]){
                   j=i+1;
                   indexB++;
                    while((a[j]==b[indexB])&&(b[indexB]!='\0')&&(a[j]!='\0')){
               
                              j++;
                              indexB++;
                   
                              
                     }
                     if(b[indexB]=='\0'){
                          location=i;
                           break;
                     }

               } 
         }
     return location;

}

int decimalBinaryMain(){
    char a[100];
    unsigned int v;
    printf("enter a string binary ");
    scanf("%s",a);
    toDecimal(a);
    
    printf("enter a number ");
    scanf("%u",&v);
    toBinari(v);
    


return 0;
}




void toDecimal(char*a){
 int i=0,mul=1,dec;
       if (a==NULL){
           dec=0;
       }else{
               
           dec=a[strlen(a)-1]-'0';
       
         for(i=strlen(a)-2;i>=0;i--){
           dec=dec+((a[i]-'0')*2*mul);
            mul=mul*2;
          
         }
       
       }

     printf("this is the decimal :  %d \n",dec);

}



void toBinari(int v){
       char a[100];
       int i=0;
     
       
       while(v>0){
        a[i]=v%2+'0';
         v=v/2;
         i++;


       } 
    a[i]='\0';
         printf("this is the binary :  ");
         for(i=strlen(a)-1;i>=0;i--){
            printf("%c",a[i]);
         }
         
        

     }
