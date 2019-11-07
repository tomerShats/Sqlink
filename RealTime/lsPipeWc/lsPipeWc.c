#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char ** argv,char**envp){
    int fd[2];
    pipe(fd);
    if(!fork()){
        close(1);
        dup2 (fd[1],1);
        close(fd[0]);
        return execlp("/bin/ls","/bin/ls","-l",NULL);
    }
      if(!fork()){
        close(0);
        dup2 (fd[0],0);
        close(fd[1]);
        return execlp("/usr/bin/wc","usr/bin/wc","-l",NULL);
    }
    //close the parents connection to the pipe
    close(fd[0]);
    close(fd[1]);
    //this is the parnet
    wait(NULL);
    wait(NULL);
    return 0;
}