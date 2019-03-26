#include <omp.h>
#include <stdio.h>

int main(){

    int nthreads = 4;
    omp_set_num_threads(nthreads);

    int i;

    #pragma omp parallel for
    for(i = 0; i < nthreads; i++){
        int tid = omp_get_thread_num();
        printf("Thread %d give you a hello world\n", tid);
    }
    
}