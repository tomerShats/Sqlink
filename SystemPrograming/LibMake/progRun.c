#include<stdio.h>
#include <dlfcn.h>
#include <stdlib.h>


int main(){

 void *handle;
 void (*cosine)();
 handle = dlopen("./libN.so", RTLD_LAZY);
  if (!handle) {
        printf( "error\n");
        return 0;
    }
    *(void **) (&cosine) = dlsym(handle, "lib1func");

    cosine();

 return 0;
}