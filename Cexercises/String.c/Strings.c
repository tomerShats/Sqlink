#include<stdio.h>
#include<string.h>


int comp(char*,char*);

void copy(char*,char*);

void cat(char*,char*);

int main(){

    char a[100],b[100];
    printf("enter str 1 ");
    scanf("%s",a);
    printf("enter str 2 ");
    scanf("%s",b);

    printf(" %d the bigger string\n",comp(a,b));
    copy(a,b);
    printf(" %s  after copy\n",a);
    cat(a,b);
    printf(" %s after cat\n",a);




    return 0;
}


  int comp(char*a,char*b){
  int i=0;

         while((a[i]!='\0')&&(b[i]!='\0')){
              if(a[i]>b[i]){
               return 1;
              }else if (a[i]<b[i]){
                return -1;
              }
            i++;
         }
     
     if(a[i]!='\0'){
         return 1;

     }else if(b[i]!='\0'){
          return -1;

      }else{ 

          return 0;
      }

}



  void copy(char*a,char*b){

          int i,j;
          for(i=0;i<=strlen(b);i++){
             a[i]=b[i];
                 
          }



}


  void cat(char*a,char*b){

     int i=0,j=0;
     for(i=strlen(a),j=0;j<strlen(b);i++,j++){
             a[i]=b[j];
                 
          }


}

