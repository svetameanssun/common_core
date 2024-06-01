#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv , char**envp)
{
    int fd_file = open("tricky.txt", O_WRONLY | O_APPEND | O_CREAT);

    
    dup2(fd_file, STDOUT_FILENO);
    printf("I AM WRITING THIS\n");


    
    return(0);
}