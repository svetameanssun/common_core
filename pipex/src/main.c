#include "../include/pipex.h"

int main(int argc, char ** argv, char ** envp)
{
    int pipe_fd[2];

    if (pipe(pipe_fd)== -1)
        manage_error("Could not create pipe");
    else
    {
       pipex(argc, argv, envp, pipe_fd);
    }
}