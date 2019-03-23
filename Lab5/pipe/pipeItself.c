//a process create a pipe to communicate with itself

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pipefds[2];
    char buf[30];

    if(pipe(pipefds) == -1){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    //write
    printf("Writing to file descriptor %d \n", pipefds[1]);
    write(pipefds[1], "I am jingweixi", 15);
    //15 is the length of writing

    //read
    printf("read from file descriptor %d \n", pipefds[0]);
    read(pipefds[0], buf, 15);
    printf(buf);
    printf("\n");
    return 0;



}