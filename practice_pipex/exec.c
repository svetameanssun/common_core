#include <stdio.h>
#include <unistd.h>

int main()
{
    //printf("I am exec.c called by execvp()\n");
    //printf("I am exec.c called by execv()\n");
    //printf("I am exec.c called by execl()\n");
    printf("I am exec.c called by execlp()\n");
    return(0);
}