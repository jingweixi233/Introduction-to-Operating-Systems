#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int fd_pipe[2] = {0};
    pid_t pid;

    if(pipe(fd_pipe) < 0){
        perror("pipe");
    }

    pid  = fork();
    
    if(pid < 0){
        perror("fork");
        return 1;
    }

    else if(pid == 0){
        char buf[] = "A message to communicate";
        write(fd_pipe[1], buf, strlen(buf));
    }
    else{
        wait(NULL);
        char str[50] = {0};
        read(fd_pipe[0], str, sizeof(str));
        printf("%s", str);
    }
    return 0;
}
