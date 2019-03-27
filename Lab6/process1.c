#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>

int main(){
    char *c = "This is operating system class. And I am a student\n";
    setbuf(stderr, NULL);
    while(*c != '\0'){
        fputc(*c, stderr);
        c++;
        sleep(2);
    }
    return 0;
}