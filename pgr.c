#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int x = 100;
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed, exit\n");
        exit(1);
    }
    else if(rc==0){
        printf("Child process's pid:%d, x value: %d\n",getpid(),x);
        x = 101;
        printf("Child process's pid:%d, x value: %d\n",getpid(),x);
    }
    else{
        printf("Parent process's pid:%d, x value:%d\n",getpid(),x);
        x = 102;
        printf("Child process's pid:%d, x value: %d\n",getpid(),x);
    }

    printf("final x value: %d\n");
    return 0;
}