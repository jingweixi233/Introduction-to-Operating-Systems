#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <semaphore.h>

int main(){
    int fd;
    int VALUE = 1;
    sem_t *mutex;
    mutex = sem_open("mutex", O_CREAT, 0666, VALUE);
    printf("Mom comes home\n");
    sem_wait(mutex);
    printf("Mom check the fridge\n");
    fd = open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
    if(lseek(fd, 0, SEEK_END) == 0){
        printf("Mom goes to buy milk\n");
        sleep(2);
        write(fd, "milk ", 5);
        printf("Mom puts the milk into fridge\n");
        if(lseek(fd, 0, SEEK_END) > 5){
            printf("The milk is too more\n");
        }
    }
    else{
        printf("Mom go away");
    }
    close(fd);
    sem_post(mutex);
    sem_unlink("mutex");
    return 0;
    
}