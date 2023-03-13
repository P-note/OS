#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
    int fd;
    int rc;
    fd = open("text.txt", O_WRONLY);
    if(fd < 0){
        perror("file open error\n");
    }

    rc = fork();
    if(rc < 0){
        fprintf(stderr, "fork failed, exit\n");
        exit(1);
    }
    else if(rc==0){
        printf("Child process's pid:%d\n",getpid());
        char childtalk[] = "Child speaking\n";
        write(fd, childtalk, 16);
    }
    else{
        printf("Parent process's pid:%d\n",getpid());
        char parenttalk[] = "Parent speaking\n";
        write(fd, parenttalk, 16);
    }

    close(fd);
    return 0;
}