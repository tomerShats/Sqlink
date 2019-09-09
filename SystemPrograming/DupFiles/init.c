
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>
#include "hashTable.h"
#include "init.h"
#include "fileOps.h"
    
int  comparePoint(void *key1, void *key2);
int intHash (void * key);
void printPoint(void * value);
void destroyFunc(void *md5Output, void *pathName);
size_t size=1000000;

 

 hashtable_t * createAll(char * path,hashtable_t * ptr){  
    hashFunction hashFunc=intHash;
    elemCompare compare=comparePoint;
    


    ptr=createHash(size,hashFunc,compare);
    if(ptr==NULL){
        return NULL;
    }else{
        return ptr;
    }

 }

 void destroyAll(hashtable_t * ptr){
     destroyElem destroyT=destroyFunc;
    destroyHash(ptr,destroyT);
    
 }
   

void destroyFunc(void *md5Output, void *pathName)
{    
    /*free(md5Output);
    free(pathName);*/
}



int  comparePoint(void *key1, void * key2){
   
     char  * a=( char *)key1;
     char  * b=( char *)key2;
    
    return strcmp(a,b);
    
}

int intHash (void * key){
    unsigned char* thisKey;
    int i = 0;
    unsigned long index=0;
    int p = 31;
    unsigned long p_pow = 1;
    thisKey = (unsigned char*)key;   
     for(i; i<16;i++)
    {
        index = (index + (thisKey[i]-'a'+1)*p_pow)%size;
        p_pow = (p_pow*p)%size;
    }
    return index;
        /*unsigned char * s=(unsigned char *) key;
        unsigned long hash = 5381;
        int c;
        int i=0;

        while (c = *s++ && i<16){
            hash = ((hash << 5) + hash) + c;  hash * 33 + c 
            hash=hash%size;
            i++;
        }
            
         printf("\n%lu\n",hash);
        return hash;*/

}

void printPoint(void *value)
{   int i=0;
    unsigned char * n=(unsigned char *) value;
    for(i=0;i<MD5_DIGEST_LENGTH;i++){
            printf("%02x",n[i]);
    }
    printf("\n");
    
    
}





