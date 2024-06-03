#include "../include/pipex.h"

char **manage_cmd(char *arg)
{
    char ** cmd_args;

    cmd_args = ft_split(arg, ' ');
    return(cmd_args);
}