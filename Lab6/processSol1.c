#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>


int main(){
    sem_t *mutex;
    char *c = "This is operating system class. And I am a student\n";
    setbuf(stderr, NULL);
    mutex = sem_open("mutex_for_stderr", O_CREAT, 0666, 1);
    sem_wait(mutex);
    while(*c != '\0'){
        fputc(*c, stderr);
        c++;
        sleep(2);
    }
    sem_post(mutex);
    sem_close(mutex);
    sem_unlink("mutex_for_stderr");
    return 0;
}