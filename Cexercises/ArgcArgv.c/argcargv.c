#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
int checkString(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
        {
            continue;
        }
        else{ return 0; }
    }
   return 1;
}

int checkNum(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if (isdigit(str1[i]))
        {
            continue;
        }
        else{ return 0; }
    }
   return 1;
}


int main(int argc,char* argv[]){
 if(argc!=3){
    printf("error there arent 3 parameters");  
    return 0;
 }else if((checkNum(argv[1])==0)&&(checkNum(argv[2])==0)){
     printf("error there isnt a number");
     return 0;
       
 }else if(checkString(argv[1])==1){
       
       printf("%s   %d",argv[1],atoi(argv[2]));
       return 0;
    
 }else if(checkString(argv[2])==1){
     printf("%s   %d",argv[2],atoi(argv[1]));
       return 0;
 }
 printf("error ");
 return 0;
}
