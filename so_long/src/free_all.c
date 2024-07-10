#include "../include/so_long.h"

void free_point(t_point *positions, int size)
{
    int i;

    i = 0;
    if (positions)
    {
        while(i < size)
        {
            free(positions);
            positions++;
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


void free_if_game(t_map *game)
{
	if (game)
	{
		free_matrix(game->matrix);
	}
	exit(1);

}
