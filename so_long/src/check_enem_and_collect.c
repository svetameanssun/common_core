#include "../include/so_long.h"

void count_enemy(t_map * game)
{
    int i;
    int j;

    i  = 0;
    j = 0;
    while(game->matrix[i])
    {
        j = 0;
        while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
        {
            game->n_enemies+= is_elem(game->matrix[i][j],'N');
            j++;
        }
        i++;
    }
    /*if (game->n_enemies == 0)
        return(ERROR_NO_ENEMY);*/
    return ;
}

int check_collect(t_map * game)
{
    int i;
    int j;

    i = 0;
    while(game->matrix[i])
    {
        j = 0;
        while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
        {
            game->n_collects += is_elem(game->matrix[i][j],'C');
            j++;
        }
        i++;
    }  
    if (game->n_collects < 1)
        return(ERROR_NO_COLLECTABLES);
    return(0);
}

