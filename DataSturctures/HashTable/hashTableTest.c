
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"
    
void destroyPointKey(void *key, void *context);
void printPoint(void * value);
int  comparePoint(void *key1, void *key2);
int intHash (void * key);
void destroyPointValue(void *key, void *context);

 

int main(){
    FILE * fp;   
    hashtable_t * ptr=NULL;
    hashFunction hashFunc=intHash;
    destroyElem destroyKey=destroyPointKey;
    destroyElem destroyValue=destroyPointValue;
    printElem printValue=printPoint;
    elemCompare compare=comparePoint;
    int num1,num2,num3,num4,num5,num6,error;
    int * find;
    size_t size;
    fp=fopen("fileDet.txt","w");
    if(fp==NULL)
    {
        return 0;
    }

    printf("enter a size\n");
    scanf("%lu",&size);

    error=insertHash(ptr,"tomer",&num1);
    if(error==1){
       printf("you cant insert, first createHash\n");
    }

    error=hashForEach(ptr,printValue);
     if(error==1){
       printf("\nyou cant print, first createHash\n");
    }

    printf("\nnow we insert 6 number:\n");
    ptr=createHash(size,hashFunc,compare);
    num1=2;
    num2=4;
    num3=9;
    num4=5;
    num5=17;
    num6=100;
    insertHash(ptr,"tomer",&num1);
    insertHash(ptr,"ravit",&num2);
    insertHash(ptr,"tom",&num3);
    insertHash(ptr,"dan",&num4);
    insertHash(ptr,"yu",&num5);
    insertHash(ptr,"kyo",&num6);
    hashForEach(ptr,printValue);

    printf("try to insert item that already exists\n");
    insertHash(ptr,"ron",&num2);
    error=insertHash(ptr,"ron",&num2);
    if(error==3){
        printf("the key is in hash\n");
    }

    printf("\ntry to find dan\n");
    error=findHash(ptr,"dan",(void**)&find);
    if(error==2){
        printf("dan is not in Hash\n");
    }else{
        printf("find Dan = %d\n",*find);
    }
    
    printf("try to find moly\n");
    error=findHash(ptr,"moly",(void**)&find);
    if(error==2){
        printf("moly is not in Hash\n");
    }else{
        printf("find moly = %d\n",*find);
    }
    
    printf("\nafter remove:\n");
    deleteHash(ptr,"tom",destroyKey,destroyValue,fp);
    hashForEach(ptr,printValue);  

    printf("\ntry to remove item that doesnt exists in the hash\n");
    error=deleteHash(ptr,"moly",destroyKey,destroyValue,fp);
     if(error==2){
        printf("moly is not in Hash\n");
    }

    destroyHash(ptr,destroyKey,destroyValue,fp);
    fclose(fp);


    return 0;
}

void destroyPointKey(void *key, void *context){
    FILE * fp=(FILE*)context;
    unsigned char * n=(unsigned char  *)key;
    
         fprintf(fp," %s - ",n);
         
    
}
void destroyPointValue(void *key, void *context){
    FILE * fp=(FILE*)context;
    int * n=(int  *) key;
    
         fprintf(fp," %d \n",*n);
        
    
}

void printPoint(void *value)
{
    int  * n=(int *) value;
    printf("%d \n",*n);
    
}


int  comparePoint(void *key1, void * key2){
   
    unsigned char  * a=(unsigned char *)key1;
    unsigned char  * b=(unsigned char *)key2;
    
    return (a-b);
    
}

int intHash (void * key){
        unsigned char * s=(unsigned char *) key;
        unsigned long hash = 5381;
        int c;
        
        while (c = *s++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;

}




