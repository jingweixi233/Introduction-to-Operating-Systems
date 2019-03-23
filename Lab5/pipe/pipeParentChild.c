//create a pipe for communication between parent and child

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int pipefd1[2], pipefd2[2];

void tellWait(void){
    if(pipe(pipefd1) < 0 || pipe(pipefd2) < 0){
        perror("pipe");
        exit(EXIT_FAILURE);
    }
}

void tellParent(void){
    if(write(pipefd2[1], "c", 1) != 1){
        perror("write");
        exit(EXIT_FAILURE);
    }
    printf("child send message to parent ---- c\n");
}

void waitParent(void){
    char c;
    if(read(pipefd1[0], &c, 1) != 1){
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Child receive message from parent  ---- %c\n", c);
}

void tellChild(void){
    printf("Parent send message to child ---- p\n");
    if(write(pipefd1[1], "p", 1) != 1){
        perror("Write");
        exit(EXIT_FAILURE);
    }
    
}

void waitChild(void){
    char c;
    if(read(pipefd2[0], &c, 1) != 1){
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Parent receive message from child ---- %c\n", c);
}

int main(){
    tellWait();
    pid_t pid;
    pid = fork();
    alarm(10);
    if(pid != 0){
        while(1){
            sleep(rand() % 2 + 1);
            tellChild();
            waitChild();
        }
    }
    else{
        while(1){
            sleep(rand() % 2 + 1);
            waitParent();
            tellParent();
        }
    }
    return 0;
}



