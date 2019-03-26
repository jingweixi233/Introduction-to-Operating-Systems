#include <stdio.h>
#define SWAP(a, b){int c;c = a;a = b;b = c;}

int main(){
    int i = 10, j = 20;
    printf("Befor swap, i = %d, j = %d \n", i, j);
    SWAP(i, j);
    printf("After swap, i = %d, j = %d \n", i, j);
    return 0;
}

