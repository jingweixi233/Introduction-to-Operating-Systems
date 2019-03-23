//2019.3.13
//kill will interrupt the program



#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
    printf("My Pid : %d\n", getpid());
    sleep(5);
    kill(getpid(), SIGSEGV);
    return 0;
}