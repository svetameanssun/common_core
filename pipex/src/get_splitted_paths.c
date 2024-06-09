#include "../include/pipex.h"
#include "../libft/libft.h"

char **get_splitted_paths(char ** envp)
{
    char *full_path;
    char ** splitted_paths;

    full_path = NULL;
    while(*envp)
    {
        if(ft_strncmp(*envp, "PATH=", 5) == 0)
        {
            full_path = (*envp + 5);
            break ;
        }
        envp++;
    }
    if (!full_path)
        manage_error("Path is not found");
    splitted_paths = ft_split(full_path, ':');
    if(!splitted_paths)
        manage_error("Could not split the full path");
    return(splitted_paths);
}