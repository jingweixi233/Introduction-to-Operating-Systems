#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *Allen(void *arg);
void *Bob(void *arg);

pthread_mutex_t book1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t book2 = PTHREAD_MUTEX_INITIALIZER;

int main(){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, Allen, NULL);
    pthread_create(&tid2, NULL, Bob, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}

void *Allen(void *arg){
    pthread_mutex_lock(&book1);
    printf("Allen borrow book1\n");
    sleep(10);
    pthread_mutex_lock(&book2);
    printf("Allen borrow book2\n");
    printf("Allen borrow two books.\n");
    pthread_mutex_unlock(&book2);
    pthread_mutex_unlock(&book1);

    return NULL;
}

void *Bob(void *arg){
    pthread_mutex_lock(&book2);
    printf("Bob borrow book2\n");
    sleep(10);
    pthread_mutex_lock(&book1);
    printf("Bob borrow book1\n");
    printf("Bob borrow two books.\n");
    pthread_mutex_unlock(&book2);
    pthread_mutex_unlock(&book1);

    return NULL;
}