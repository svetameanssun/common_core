#include "../include/so_long.h"

void position_enemies(t_map *game, int enemies)
{
	int i;
	int j;
    int k;

    i = 0;
	j = 0;
    k = 0;
    game->enemies_pos = malloc(sizeof(t_point) * enemies);
    while(game->matrix[i] && k < enemies)
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

int check_enemy(t_map * game)
{
    int enemy;
    int i;
    int j;

    enemy = 0;
    i  = 0;
    j = 0;
    while(game->matrix[i])
    {
        j = 0;
        while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
        {
            enemy+= is_elem(game->matrix[i][j],'N');
            j++;
        }
        i++;
    }
    if (enemy < 1)
        return(ERROR_NO_ENEMY);
    game->n_enemies = enemy;
    position_enemies(game, enemy);
    return(0);
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
    position_collects(game, game->n_collects);
    return(0);
}

void position_collects(t_map *game, int collects)
{
	int i;
	int j;
    int k;

    i = 0;
	j = 0;
    k = 0;
    game->coll_pos = malloc(sizeof(t_point) * collects);
    while(game->matrix[i] && k < collects)
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