#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "files.h"


void lastNlines(int n,char * name){

   int * lastN;
   char ch [512];
   int i=0,endLocation;
   FILE * fp;
   lastN=(int*)malloc(sizeof(int)*n);
   if((fp=fopen(name,"r"))!=NULL){
       fseek(fp,0,2);
       endLocation=ftell(fp);

       fseek(fp,0,0);
       while(!feof(fp)){
              lastN[i%n]=ftell(fp);
              
              fgets(ch,512,fp);
              if(ftell(fp)==endLocation)
              {
                 break;
              }
             
               i++;
              
        }
       
       fseek(fp,0,2);
       endLocation=ftell(fp);
       fseek(fp,lastN[(i+1)%n],0);
        
       while(!feof(fp)){
            
            fgets(ch,512,fp);
            printf("%s\n",ch);
             if(ftell(fp)==endLocation)
              {
                 break;
              }
            
         
       }
      
    
    fclose(fp);
    free(lastN);
  }


}

void countWord(char * name){
  FILE * fp;
  FILE * out;
  char str [100];
  char s[50]="out.txt";
  Count_t ** countword;
  int i=0,j,flag=0;
  if((fp=fopen(name,"r"))!=NULL)
  {

      countword=malloc(sizeof(Count_t *));
      while(!feof(fp))
      {
         
          fscanf(fp,"%s",str);
          for(j=0;j<i;j++)
          {
             if(strcmp (countword[j]->word,str)==0)
             {
                 flag=1;
                 countword[j]->count++;
                 break;
             }
          }
          if(flag==0){
              if(i>0)
              {
                 countword=(Count_t **)realloc(countword, sizeof(Count_t *)*(i+1)); 
              }
              countword[i]=(Count_t *)malloc(sizeof(Count_t));
              strcpy(countword[i]->word, str);
              countword[i]->count=1;
              i++; 
   
          }
        flag=0;

    }
    if((out=fopen(s,"w"))!=NULL)
   {
        for(j=0;j<i;j++){
        fprintf(out," %s   %d\n",countword[j]->word,countword[j]->count);
        }
      fclose(out);
      fclose(fp);
   }
}
}


void countChar(char * name){
  FILE * fp;
  char bigChar [26];
  char smallChar [26];
  char ch;
  int i=0;
  for(i=0;i<26;i++){
      bigChar [i]=0;
      smallChar [i]=0;
  }

  if((fp=fopen(name,"r"))!=NULL){
     
        while(!feof(fp)){
             ch=getc(fp);
             if((ch>='A')&&(ch<='Z')){

                    bigChar[ch-'A']++;

              }else  if((ch>='a')&&(ch<='z')){

              smallChar[ch-'a']++;

               }
           
         
          }
      for(i=0;i<26;i++){
           if(bigChar[i]>0){
                printf(" %c    %d\n",i+'A',bigChar[i]);
           }else if(smallChar[i]>0){
                printf(" %c    %d\n",i+'a',smallChar[i]);
           }
       }
     
     fclose(fp);
  }
}





