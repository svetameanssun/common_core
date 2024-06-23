#include "../include/so_long.h"

void free_point(t_map *game)
{
    int size;
    int i;

    size = game->n_collects;
    i = 0;
    if (game->coll_pos)
    {
        while(i < size)
        {
            free(game->coll_pos);
            game->coll_pos++;
            i++;
        }
    }
}

void	free_matrix(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i] != NULL)
		{
			free (map[i]);
			i++;
		}
		free (map);
	}
}

void free_game(t_map *game)
{
    free_matrix(game->matrix);
    free_point(game);
    
	game->mlx = NULL;
}
