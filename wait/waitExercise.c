/*

Now you have learnt how to use fork, exec*() and wait/waitpid. Try to write code to combine the uses of them to execute ls in a new process properly (without zombie!).

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(){
    int pid;
    int status;
    pid = fork();

    if(pid == 0){
        printf("It is the child process\n");
        execlp("ls", "ls", "-l", NULL);
        exit(0);
    }
    else{
        waitpid(pid, &status, WUNTRACED);
        printf("The child process exit\n");
    }
    return 0;
}