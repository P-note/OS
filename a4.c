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
        printf("Child PID:%d\n", getpid());
        char *arg[]={"ls",NULL};
        execv("/bin/ls",arg);
        printf("This shouldn't print out!\n");
    }
    else{
        int wc = wait(NULL);
        printf("Parent PID:%d\n",getpid());
    }
}