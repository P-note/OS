#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    int fd[2];
    int rc, rc2;
    char message[9];
    if(pipe(fd) < 0){
        printf("pipe error mate");
        return -1;
    }
    
    rc = fork();

    if(rc < 0){
        fprintf(stderr,"fork error mate");
        exit(1);
    }
    else if(rc == 0){
        dup2(fd[1], STDOUT_FILENO);
        printf("Transfer");
    }

    rc2=fork();
    if(rc2 < 0){
        fprintf(stderr,"fork2 error mate");
        exit(1);
    }
    else if(rc2==0){
        dup2(fd[0], STDIN_FILENO);
        scanf("%s", message);
    }

    printf("%s", message);
}