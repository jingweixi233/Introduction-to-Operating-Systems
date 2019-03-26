//In this example, we want to pass more than one argument to the function, so we create a pointer which points to a struct we have created, transfer it into (void *) and pass it to function. In function, we transfer the type of pointer to the real type, so that we can properly use it.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct args{
    char *name;
    int age;
};

void *hello(void *input){
    printf("name: %s\n", ((struct args*)input) -> name);
    printf("age: %d\n", ((struct args*)input) -> age);
    return NULL;
}

int main(){
    struct args *Allen = (struct args *)malloc(sizeof(struct args));
    char allen[] = "Allen";
    Allen -> name = allen;
    Allen -> age = 20;

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *)Allen);
    pthread_join(tid, NULL);
    return 0;
}
