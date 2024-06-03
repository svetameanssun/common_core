#include "../include/pipex.h"
#include "../libft/libft.h"

void ft_exec(char *cmd_path, char *arg, char **envp)
{
    char **cmd;
    cmd = cmd_split(arg);
    if (!cmd)
    {
        free(cmd_path);
        manage_error("Error splitting arguments");
    }
    if (execve(cmd_path, cmd, envp) == -1)
    {
        ft_free_table(cmd);
        free(cmd_path);
        manage_error("Execution failed");
    }
}