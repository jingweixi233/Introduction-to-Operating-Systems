/* Header Declaration */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

/* Function Declaration */
extern int *readdata(char *filename, long *number);

void *bubbleSort(int *arr){
    
}
/* Main */

int main(int argc, char *argv[]) {
    if(argc!=5) {
        printf("usage:\n");
        printf("    ./asg3-pthread inputfile1 inputfile2 outputfile ThreadNum\n");

        return -1;
    }

    int *array1, *array2;
    long num1, num2;

    array1 = readdata(argv[1], &num1);
    array2 = readdata(argv[2], &num2);

    /* do your assignment start from here */
    
    pthread_t tid1;
    tid1 = pthread_create(&tid1, NULL, bubbleSort, array1);
    pthread_join(tid1, NULL);

    pthread_t tid2;
    tid2 = pthread_create(&tid2, NULL, bubbleSort, array2);
    pthread_join(tid2, NULL);

    
    
    int *res;// initialize by yourself, this array will be used to output your result
    long len;// the length of res, will be used to output your result

    

    FILE *fp=fopen(argv[3], "w");
    /* you should call "output(fp, res, len)" to output your result*/

    fclose(fp);

    return 0;
}