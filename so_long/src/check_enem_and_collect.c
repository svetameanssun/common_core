#include "../include/so_long.h"



int check_enemy(t_map * game)
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
    if (game->n_enemies == 0)
        return(ERROR_NO_ENEMY);
    game->n_enemies = game->n_enemies;
    position_enemies(game);
    return(0);
}

void position_enemies(t_map *game)
{
	int i;
	int j;
    int k;

    i = 0;
	j = 0;
    k = 0;
    game->enemies_pos = malloc(sizeof(t_point) * game->n_enemies);
    if(game->enemies_pos == NULL)
        manage_prog_error(game, ERROR_MALLOC);
    while(game->matrix[i] && k < game->n_enemies)
    {
        j = 0;
        while(game->matrix[i][j])
        {
            if(game->matrix[i][j] == 'N')
            {
                game->enemies_pos[k].x = j;
                game->enemies_pos[k].y = i;
                k++;
            }
            j++;
        }
        i++;
    }
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
    position_collects(game);
    return(0);
}

void position_collects(t_map *game)
{
	int i;
	int j;
    int k;

    i = 0;
	j = 0;
    k = 0;
    game->coll_pos = malloc(sizeof(t_point) * game->n_collects);
    if(game->coll_pos == NULL)
        manage_prog_error(game, ERROR_MALLOC);
    while(game->matrix[i] && k < game->n_collects)
    {
        j = 0;
        while(game->matrix[i][j])
        {
            if(game->matrix[i][j] == 'C')
            {
                game->coll_pos[k].x = j;
                game->coll_pos[k].y = i;
                k++;
            }
            j++;
        }
        i++;
    }
}


