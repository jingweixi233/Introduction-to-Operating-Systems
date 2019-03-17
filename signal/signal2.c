//You can override the default signal handler to IGN (ignore) or a custom handler. This is useful if you would like your program to react for certain kind of signals.

//The program below sets the signal handler of SIGINT to SIG_IGN. The OS will ignore the signal so it has no response to CTRL-C.

//When you use the CTRL-C, it handles it with ignore function
//So you can not get it stop with CTRL-C

#include <stdio.h>
#include <signal.h>

int main(){
    signal(SIGINT, SIG_IGN);
    printf("Put into while 1 loop\n");
    while(1){}
    printf("OK1\n");
    return 0;
}