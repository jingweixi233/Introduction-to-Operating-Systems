//The parent process communicate with the child process on pipe


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pipefds[2];
    pid_t pid;
    char buf[30];

    if(pipe(pipefds) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    memset(buf, 0, 30);
    pid = fork();
    if(pid > 0){
        printf("Parent write in pipe\n");
        close(pipefds[0]);
        write(pipefds[1], "I am jingweixi", 15);
        close(pipefds[1]);
        wait(NULL);
    }
    else{
        //child
        close(pipefds[1]);
        while(read(pipefds[0], buf, 1) == 1){
            printf("Child read from pipe --- %s \n", buf);
        }

        close(pipefds[0]);
        printf("Child exiting");
        exit(EXIT_SUCCESS);
    }
    return 0;
}