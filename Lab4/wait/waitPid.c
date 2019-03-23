/*

waitpid() takes 3 parameters. The first one is child pid, therefore this is more specific than the previous wait().

The second one stores the status of the child. Whenever the child terminates/suspends, it will store the status code in the middle parameter. Note that it accepts a pointer only.

The third is the options for waitpid(). You can change various behaviour, for example, returns immediately if no child has exited: WNOHANG; also returns if the child is stopped (eg: by Ctrl-Z): WUNTRACED.

There are macros to further tell you more information about the child. You can use WIFEXITED(status) to check if the child is returned normally (i.e. by return or exit()). In addition you even can know the exit code (Only least significant 8 bits of status code is available to parents) by using WEXITSTATUS(status).

waitpid(pid, &status, option)

First parameter: The parent process will wait the child process with waitpid to terminate.

Second parameter: The status is the status of child process's exit.

Third parameter: option1

option1-WNOHANG: If the child process does not exit, it will not block the parent process and return 0;

option2-WUNTRACED: The parent process will wait the child process. And it will return the status of child process;

option3-0: The parent will be blocked and wait the child process, just like Wait(NULL);

*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int pid;
    int status;
    int i;
    if(!(pid = fork())){
        printf("Child pid = %d \n", getpid());
        for(i = 0; i < 100; i++){  
            printf("$\n");
            sleep(1);
        }
        exit(0);
    }

    waitpid(pid, &status, WNOHANG);
    if(WIFEXITED(status)){
        printf("Exit Normally\n");
        printf("Exit status = %d\n", WEXITSTATUS(status));
    }
    else{
        printf("Exit Not Normal\n");
    }
    return 0;
}