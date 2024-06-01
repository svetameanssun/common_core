#include "../include/pipex.h"
#include "../libft/libft.h"

void start_child_one(char ** argv, char **envp, int * pipe_fd)
{
    int infile_fd;
    char *cmd_path;

    close(pipe_fd[READ]);
    if ((infile_fd = open(argv[1], O_RDONLY | O_CREAT, 0662)) == -1)
        manage_error("Could not open infile");
    if ((dup2(infile_fd, STDIN_FILENO)) == -1)
        manage_error("Could not redirect infile_fd");
    close(infile_fd);
    if(dup2(pipe_fd[WRITE], STDOUT_FILENO) == -1)
        manage_error("Could not redirect pipe_fd[1] to write");
    close(pipe_fd[WRITE]);
    cmd_path = get_cmd_path(argv[2], envp);
    if (!cmd_path)
        manage_error("Comand not found");
    ft_exec(cmd_path, argv[2], envp);
    exit(EXIT_SUCCESS);
}