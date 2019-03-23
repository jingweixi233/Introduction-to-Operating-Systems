//fork
//parent process pid
//child process pid

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    printf("Before Fork, My pid %d\n", getpid());
    fork();
    printf("After Fork, My pid %d\n", getpid());
    return 0;
}