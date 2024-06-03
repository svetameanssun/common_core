#include "../include/pipex.h"

char * get_cmd_path(char *arg, char ** envp)
{
    char **cmd;
    char **splitted_paths;
    char *cmd_path;
    int i;

    i = 0;
    cmd_path = NULL;
    splitted_paths = get_splitted_paths(envp);
    cmd = ft_split(arg, ' ');
    while(splitted_paths[i])
    {
        cmd_path = ft_strjoin(ft_strjoin(splitted_paths[i], "/"), cmd[0]);
        if (access(cmd_path, X_OK))
            break ;
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }
    ft_free_table(splitted_paths);
    return(cmd_path);
    
}