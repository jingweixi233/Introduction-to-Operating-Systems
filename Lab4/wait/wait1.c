/*
We would like to suspend the parent and let the child finish execution.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    printf("Before fork...\n");
    if(fork() == 0){
        printf("Hello world. \n");
        exit(0);
    }
    printf("After fork .. \n");
    return 0;
}