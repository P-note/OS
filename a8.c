#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void){
    int fd[2];
    int rc, rc2;
    int state;
    char message[100];
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
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        write(1, "Hello to rc2, this is from rc1\n", 32);
    }
    else{
        rc2=fork();
        if(rc2 < 0){
            fprintf(stderr,"fork2 error mate");
            exit(1);
        }
        else if(rc2==0){
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            int n = read(fd[0], message, sizeof(message));
            printf("%s", message);
        }
        else{
            waitpid(rc, &state, 0);
            waitpid(rc2, &state, 0);
        }
    }

    return 0;
}