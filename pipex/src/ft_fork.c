#include "../include/pipex.h"

void ft_fork(char ** argv, char ** envv, int *pipe_fd)
{
    int pid_1;
    int pid_2;

    if ((pid_1 = fork()) == -1)
        manage_error("Could not fork 1st time");
    if (pid_1 == 0)
        start_child_one(argv, envv, pipe_fd);
    else
    {
        close(pipe_fd[WRITE]);
        waitpid(pid_1, NULL, 0);
        if ((pid_2 = fork()) == -1)
            manage_error("Could not fork 2nd time");
        if (pid_2 == 0)
            start_child_two(argv, envv, pipe_fd);
        else
        {
            close(pipe_fd[0]);
            waitpid(pid_2, NULL, 0);
        }
    }

}
