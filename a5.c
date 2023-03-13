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
        printf("child pid is: %d\n",getpid());
        printf("hello\n");
    }
    else{
        int wc = wait(NULL);
        printf("parent pid is: %d\n",getpid());
        printf("value of wc is: %d\n",wc);
        printf("goodbye\n");
    }
}