#include "../include/pipex.h"
#include "../libft/libft.h"

void start_child_two(char ** argv, char **envp, int *pipe_fd)
{
    int outfile_fd;
    char *cmd_path;

    close(pipe_fd[1]);
    outfile_fd = open(argv[4],O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile_fd == -1)
        manage_error("Could not open outfile");
    if (dup2(pipe_fd[0],STDIN_FILENO) == -1)
        manage_error("Could not redirect stdin to fd[0]");
    close(pipe_fd[0]);
    if (dup2(outfile_fd, STDOUT_FILENO)== -1)
        manage_error("Could not redirect  stdout to outfile");
    close(outfile_fd);
    cmd_path = get_cmd_path(argv[3], envp);
    if (!cmd_path)
        manage_error("Command not found");
    ft_exec(cmd_path, argv[3], envp);

    exit(EXIT_SUCCESS);
}
