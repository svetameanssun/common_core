#include "../include/pipex.h"
#include "../libft/libft.h"

char **cmd_split(char *arg)
{
    int count;
    char **cmd_splitted;

    count = char_count('\'', arg);
    if (count == 2)
    {
        cmd_splitted = ft_split(arg, '\'');
        cmd_splitted[0] = ft_strtrim(cmd_splitted[0], " ");
        return(cmd_splitted);
    }
    else
    {
        cmd_splitted = ft_split(arg, ' ');
        return(cmd_splitted);
    }
}