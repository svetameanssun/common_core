#include "../include/pipex.h"
#include "../libft/libft.h"

void ft_free_table(char **table)
{
    int i;

    i = 0;
    while(table[i])
    {
        free(table[i]);
        i++;
    }
    free(table);
    *table = NULL;
}