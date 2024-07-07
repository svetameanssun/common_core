#include "../include/so_long.h"

static char	*fill(char **map, int rows, int columns)
{
	map[rows][columns] = '1';
	if (map[rows - 1][columns] != '1')
		fill(map, (rows - 1), columns);
	if (map[rows + 1][columns] != '1')
		fill(map, (rows + 1), columns);
	if (map[rows][columns - 1] != '1')
		fill(map, rows, (columns -1));
	if (map[rows][columns + 1] != '1')
		fill(map, rows, (columns + 1));
	return (*map);
}

int	part_floodfill(char	**copymap, t_map *game)
{
	int	rows;
	int	columns;

	rows = 0;
	columns = 0;
	while (copymap[columns][rows] != '\0')
	{
		rows = 0;
		while (copymap[columns][rows] != '\n')
		{
			if (copymap[columns][rows] == 'C' || copymap[columns][rows] == 'E')
				manage_map_error(game, ERROR_NO_PATH);
			rows++;
		}
		columns++;
	}
	free_matrix(copymap);
	return (0);
}
void n_to_one(char **copymap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while(copymap[i]!= NULL)
	{
		j = 0;
		while(copymap[i][j] != '\0')
		{
			if(copymap[i][j] == 'N')
				copymap[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	floodfill(t_map *game)
{
	char	**copymap;
	int		rows;
	int		columns;
	int		i;

	i = 0;
	pos_player(game);
	copymap = malloc(sizeof(char *) * (game->map_dim.y + 1));
	if(copymap == NULL)
		manage_prog_error(game, ERROR_MALLOC);
	while (i < game->map_dim.y)
	{
		copymap[i] = ft_strdup(game->matrix[i]);
		i++;
	}
	copymap[i] = NULL;
	n_to_one(copymap);
	fill(copymap, game->player.y, game->player.x);
	part_floodfill(copymap, game);
	return (0);
}

t_point *find_collects(t_map *game)
{
	t_point *collects;
	t_point pnt;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	collects = (t_point *)malloc(sizeof(t_point) * game->n_collects);
	if(collects == NULL)
		manage_prog_error(game, ERROR_MALLOC);
	while(i < game->map_dim.y && k < game->n_collects)
	{
		j = 0;
		while(j < game->map_dim.x)
		{
			if(game->matrix[i][j] == 'C')
			{
				pnt.x = j;
				pnt.y = i;
				collects[k] = pnt;
				k++;
			}
			j++;
		}
		i++;
	}
	return(collects);
}

void	pos_player(t_map *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->matrix[i][j] != 'P')
	{
		j = 0;
		while (game->matrix[i][j] != '\n')
		{
			if (game->matrix[i][j] == 'P')
				break ;
			else
				j++;
		}
		if (game->matrix[i][j] == 'P')
			break ;
		i++;
	}
	game->player.y = i;
	game->player.x = j;
}