/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 12:39:07 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/16 15:46:39 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game->columns = 0;
	game->rows = 0;
	game->collects = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_column = 0;
	game->exit_row = 0;
	game->moves = 0;
}