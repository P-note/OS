#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork error mate");
        exit(1);
    }
    else if(rc == 0){
        printf("hello\n");
    }
    else{
        int wc = wait(NULL);
        printf("value of wc is: %d\n");
        printf("goodbye\n");
    }
}