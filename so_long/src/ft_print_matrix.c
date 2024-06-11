#include "../include/so_long.h"

void ft_print_matrix(char **matrix)
{

    while(*matrix)
    {
        printf("%s\n", *matrix);
        matrix++;
    }
}