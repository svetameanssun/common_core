#include "../include/pipex.h"

void pipex(int argc, char **argv, char **envp, int pipe_fd[2])
{
    int pid;
    int infile_fd;
    int outfile_fd;
    int status;

    infile_fd = open(argv[1], O_RDONLY);
    outfile_fd = open(argv[4], O_WRONLY | O_CREAT, 0622);
    if ((pid = fork())== -1)
        manage_error("Error forking");
    else if (pid == 0)
    {
        close(pipe_fd[1]);
        dup2(infile_fd,STDIN_FILENO);
        dup2(pipe_fd[0], STDOUT_FILENO);
        execve(set_path(manage_cmd(argv[2]),envp),manage_cmd(argv[2]), envp);
    }
    else
    {
        waitpid(pid, &status, 0);
        close(pipe_fd[0]);
        dup2(pipe_fd[1], STDIN_FILENO);
        dup2(outfile_fd, STDOUT_FILENO);
        execve(set_path(manage_cmd(argv[3]),envp), manage_cmd(argv[3]), envp);
    }
}
