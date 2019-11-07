
#include <iostream> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <unistd.h>
using namespace std; 
  
int main() 
{ 
    // ftok to generate unique key 
    key_t key = ftok("shmfile",65); 
  
    // shmget returns an identifier in shmid 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
  
    // shmat to attach to shared memory 
    int * n = (int*) shmat(shmid,(void*)0,0); 
    *n=0;
    
    while(1){
      (*n)++;
      cout<<*n<<endl;
      sleep(1);
    }
   shmdt(n); 
      
    
    return 0; 
} 
