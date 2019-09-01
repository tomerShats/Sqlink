#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("i in other function\n");
    return 1;
}