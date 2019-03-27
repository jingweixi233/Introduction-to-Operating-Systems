#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void granted();
int checkPasswd();

int checkPasswd(){
    char passwd[16];
    printf("Enter your password: ");
    gets(passwd);
    if(strcmp(passwd, "passwd1")){
        printf("\nYou fail\n");
    }
    else{
        granted();
    }
}

void granted(){
    printf("You are right\n");
    return;
}

int main(){
    checkPasswd();
    return 0;
}