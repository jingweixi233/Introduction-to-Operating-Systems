#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

int main(){
    sem_t *ns, *ew;
    ns = sem_open("ns", O_CREAT, 0666, 1);
    ew = sem_open("ew", O_CREAT, 0666, 0);

    int i, car = 0, loop = 3;
    
    for(i = 0; i < loop; i++){
        sem_wait(ns);
        printf("The road from north to south is open\n");
        sleep(1);
        printf("nsCar %d passed\n", car++);
        sem_post(ew);
    }
    printf("NS timeup, nsCar all passed\n");
    sem_close(ns);
    sem_close(ew);
    sem_unlink("ns");
    sem_unlink("ew");
    return 0;
}