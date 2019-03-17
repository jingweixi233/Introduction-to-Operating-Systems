#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int i;
    pid_t pid;

    //for another process
    pid = fork();
    
    if(pid < 0){ //error
        printf("Fork failed");
        return 1;
    }

    else if(pid == 0){ //run program.c
        execl("./program", "program", NULL);
    }
    else{
        wait(NULL);
        printf("Child complete\n");
    }
    return 0;
}
