#include <stdio.h>
#include <unistd.h>

int main(void){
    int x = 100;
    int rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed, exit\n");
        exit(1);
    }
    else if(rc==0){
        printf("Child process's x value: %d\n",x);
    }
    else{
        printf("Parent process's x value:%d\n",x);
    }
    return 0;
}