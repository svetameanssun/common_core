#include "../include/pipex.h"

void start_child_one(char ** argv, char **envv, int * pipe_fd)
{
    int infile_fd;
    char *path;

    close(pipe_fd[READ]);
    if ((infile_fd = open(argv[1], O_RDONLY)) == -1)
        manage_error("Could not open infile");
    if ((dup2(infile_fd, STDIN_FILENO)) == -1)
        manage_error("Could not redirect infile_fd");
    close(infile_fd);
    if(dup2(pipe_fd[WRITE], STDOUT_FILENO) == -1)
        manage_error("Could not redirect pipe_fd[1] to write");
    close(pipe_fd[WRITE]);
    path = get_cmd_path(argv[2], envv);
    if (!path)
        manage_error("Comand not found");
    ft_execute(path, &argv[2], envv);
    exit(EXIT_SUCCESS);
}