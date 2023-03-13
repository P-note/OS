#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int rc = fork();
    if(rc < 0){
        fprintf(stderr,"fork error mate");
        exit(1);
    }
    else if(rc == 0){
        printf("child pid is: %d\n",getpid());
        close(STDOUT_FILENO);
        printf("Will this print out?\n");
    }
    else{
        int wc = waitpid(rc, &state, 0);
        printf("parent pid is: %d\n",getpid());
        printf("value of wc is: %d\n",wc);
    }
}