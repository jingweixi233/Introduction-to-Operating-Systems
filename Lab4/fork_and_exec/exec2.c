/*

Take a note of the main function parameter. There is an extra item of char * envp[]. This allows the program to retrieve the system environment variable.

*/


#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
    int i;
    for(i = 0; envp[i]; i++){
        printf("[%d] = %s\n", i, envp[i]);
    }
    return 0;
}