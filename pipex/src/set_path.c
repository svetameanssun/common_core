#include "../include/pipex.h"

static char **find_path(char **envp)
{
    char * full_path;
    char **splitted_paths;

    full_path = NULL;
    while(*envp)
    {
        if(ft_strncmp("PATH=", *envp, 5) == 0)
        {
            full_path = *envp + 5;
            break;
        }
        envp++;
    }
    splitted_paths = ft_split(full_path, ':');
    return(splitted_paths);
}

char *set_path(char **cmd, char **envp)
{
    char *path;
    char ** splitted_paths;

    splitted_paths = find_path(envp);
    while(*splitted_paths)
    {
        path = ft_strjoin(ft_strjoin(*splitted_paths, "/"), cmd[0]);
        if(access(path, X_OK) == 0)
        {
            break;
        }
        free(path);
        path = NULL;
        splitted_paths++;
    }
    return(path);
}
