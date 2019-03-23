//getcwd() get the current path of file

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

//char *getcwd(char *buf, size_t, size);

int main(){
    char cwd[PATH_MAX + 1];
    if(getcwd(cwd, PATH_MAX + 1) != NULL){
        printf("Current working Dir: %s\n", cwd);

    }
    else{
        printf("Error Occured!\n");
    }
    return 0;
}



