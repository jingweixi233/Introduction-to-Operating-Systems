#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int res;
    printf("Before fork, Pid = %d \n", getpid());
    res = fork();
    if(res == 0){
        printf("I am child! Pid = %d \n", getpid());
        
    }
    else{
        wait(NULL);
        printf("I am parent! Pid = %d \n", getpid());
    }
    printf("Program Terminate\n");
    return 0;

}