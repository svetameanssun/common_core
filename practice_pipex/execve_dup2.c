#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char ** argv, char ** envp)
{
    int infile_fd = open("infile.txt", O_RDONLY );

    char cmd_path[] = "/usr/bin/wc";

    execve(cmd_path, argv, envp);

    return(0);
}