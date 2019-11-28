#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <limits.h> 
#include "StructReg.h"

void err(int val) {
	if(val==-1) {
		perror("putget");
		exit(1);
	}
}

void * producer(void * arg) {
	int fd;
	struct mq_reg reg;
	reg.data="hello";
	reg.size=strlen(reg.data);
	
	err(fd=open("/dev/qm2", O_RDWR));
	for(int i=0;i<100;i++) {
		err(ioctl(fd,MQ_SEND_MSG,&reg));
	}
	err(close(fd));
	return NULL;
}

void * consumer(void * arg) {
	int fd;
	char* str=(char*)malloc(sizeof(char)*100);
	err(fd=open("/dev/qm2",O_RDONLY));
	for(int i=0;i<100;i++) {
		err(ioctl(fd,MQ_RECV_MSG,str));
		printf("%s \n",str);
	}
	free(str);
	err(close(fd));
	return NULL;
}

static void check_pthread_error(int ret) {
	if(ret) {
		fprintf(stderr, "there was a pthread error %d\n", ret);
		exit(EXIT_FAILURE);
	}
}

const int pronum=100;
const int connum=100;

int main(int argc, char** argv, char** envp) {
	pthread_t producers [pronum];
	pthread_t consumers [connum];
	for(int i=0;i<pronum;i++){
		int ret=pthread_create(&producers[i],NULL, producer, NULL);
		check_pthread_error(ret);
	}
	for(int i=0;i<connum;i++){
		int ret=pthread_create(&consumers[i],NULL, consumer, NULL);
		check_pthread_error(ret);
	}
	for(int i=0;i<pronum;i++){
		int ret=pthread_join(producers[i], NULL);
		check_pthread_error(ret);
	}
	for(int i=0;i<connum;i++){
		int ret=pthread_join(consumers[i], NULL);
		check_pthread_error(ret);
	}
	return EXIT_SUCCESS;
}
