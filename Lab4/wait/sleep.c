/*
By using sleep(), parent can put to a suspended state and wait for the child. 
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
    sleep(1);
    printf("After fork .. \n");
    return 0;
}