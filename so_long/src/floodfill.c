/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:24:33 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/10 17:29:52 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*fill(char **map, int rows, int columns)
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
	player_current_pos(game);
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
	fill(copymap, game->player_pos.y, game->player_pos.x);
	part_floodfill(copymap, game);
	return (0);
}
