#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    int fd;
    printf("Dad comes home\n");
    sleep(1);
    fd=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd, 0, SEEK_END) == 0){
        printf("Dad will go to buy milk\n");
        sleep(1);
        write(fd, "milk ", 5);
        printf("Dad put the milk into fridge\n");
        if(lseek(fd, 0, SEEK_END) > 5){
            printf("The milk is too more\n");
        }
    }
    else{
        printf("Dad go away\n");
    }
    close(fd);
    return 0;
}