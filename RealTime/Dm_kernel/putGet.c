#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include<pthread.h>
#include <limits.h> 
#include "StructReg.h"
#define PRONUM 100
#define CONSUM 100
 void * producer(void * arg) 
{
   int fd;
   int size;
   struct mq_reg reg;
   
   int i=0;
   fd=open("/dev/qm2",O_RDWR);
   if(fd<0){
       printf("error fd\n");
       
   }
   while(i<100){
       reg.data="hello";
       reg.size=strlen(reg.data);
       size=ioctl(fd,100,&reg);
       i++;
   }
   
   
   
  


      
}

void * consumer(void * arg) 
{   int fd;
    int ret;
    struct mq_reg reg;
    char* str=malloc(sizeof(char)*100);
    int i=0;
    fd=open("/dev/qm2",O_RDONLY);
    if(fd<0){
        fprintf(stderr, "error fd\n");
        
    }
    while(i<100){

    
       ret = ioctl(fd,101,str);
       if(ret<0) {
        fprintf(stderr, "error in iotcl\n");
       }
        printf("%s \n",str);
        i++;
    }
   
   
   
}

int main() {

    pthread_t producers [PRONUM];
    pthread_t consumers [CONSUM];
    int i,j,w;
    
    
     
    for(i=0;i<PRONUM;i++){
       pthread_create(&producers[i],NULL, producer, NULL);
       
    }

    for(j=0;j<CONSUM;j++){
        pthread_create(&consumers[j],NULL, consumer, NULL);
        
    }

    for(w=0;w<PRONUM;w++){
     pthread_join(producers[w], NULL);
    }
    
    
    return 0;
}
