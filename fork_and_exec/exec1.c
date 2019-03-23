/*
The above program illustrates the function of exec(). execl() is one of the family members of exec(), which is responsible for calling external programs.

First the program will print out Using *execl* to exec ls -l...

the program will execute /bin/ls program, with the supplied arguments.

After this step, the code of the process is changed to the target program and it never returns to the original code. As the result, the line Program Terminated is not printed.

execlp(parameter1, p2, p3, p4 ...)
p1 instruction file
p2 instruction name
p3, p4, p5 ... instruction parameters
*/


#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Using execlp exec ls -l...\n");
    execlp("ls", "ls", NULL);
    printf("Program Terminate\n");
    return 0;
}