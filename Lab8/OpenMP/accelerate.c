#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>

void test(){
    int a = 0;
    int i;
    for(i = 0; i < 1000000000; i++){
        a++;
    }
}

int main(){
    struct timeval start, end;
    gettimeofday(&start, NULL);

    int i;
    #pragma omp parallel for
    for(i = 0; i < 8; i++){
        test();
    }

    gettimeofday(&end, NULL);
    printf("It will use time %f\n", (double)((end.tv_sec * 1000000 + end.tv_usec)- (start.tv_sec * 1000000 + start.tv_usec))/1000000);
}