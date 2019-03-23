//When you want to kill the program, it will go to function handler.

#include <stdio.h>
#include <signal.h>

void handler(int signal){
    printf("Signal %d Receiced. Kill me idf you can\n", signal);
    printf("haha\n");
}

int main(){
    signal(SIGINT, handler);
    printf("Put into while 1 loop..\n");
    while(1){

    }
    printf("OK!\n");
    return 0;
}