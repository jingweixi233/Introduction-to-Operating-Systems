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
    pid  = fork();
    
    if(pid < 0){ //error
        printf("Fork failed");
        return 1;
    }

    else if(pid == 0){
        for(i = 0; i < 1000; i++){
            printf("This is a child\n");
        }
    }
    else{
        for(i = 0; i < 1000; i++){
            printf("process\n");
        }
    }
    return 0;
}