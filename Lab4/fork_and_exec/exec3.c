/*
If errors occur while executing exec*(), it will return to the program and continue execution. The return value is -1, and errno is set to indicate the error.
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(){
    printf("Try to execute lss\n");
    execl("/bin/lls", "lls", NULL);
    printf("execl returned! errno is [%d]\n", errno);
    perror("The error message is : ");
    return 0;

}