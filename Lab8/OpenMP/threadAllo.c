#include <omp.h>
#include <stdio.h>

int main(){

    int nthreads = 4;
    omp_set_num_threads(nthreads);

    int i;

    #pragma omp parallel for
    for(i = 0; i < 9; i++){
        int tid = omp_get_thread_num();
        printf("Thread %d give you a hello world\n", tid);
    
        int j = 0;
        int a = 0;
        for(j = 0; j < 100000000; j++){
            a++;
        }
    }
}