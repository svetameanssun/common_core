/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:23:26 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 17:02:51 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_enemy(t_map	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->matrix[i])
	{
		j = 0;
		while (game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
		{
			game->n_enemies += is_elem(game->matrix[i][j], 'N');
			j++;
		}
		i++;
	}
	return ;
}

int	check_collect(t_map	*game)
{
	int	i;
	int	j;

	i = 0;
	while (game->matrix[i])
	{
		j = 0;
		while (game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
		{
			game->n_collects += is_elem(game->matrix[i][j], 'C');
			j++;
		}
		i++;
	}
	if (game->n_collects < 1)
		return (ERROR_NO_COLLECTABLES);
	return (0);
}

int	check_player(t_map	*game)
{
	int	player;
	int	i;
	int	j;

	player = 0;
	i = 0;
	j = 0;
	while (i < game->map_dim.y)
	{
		j = 0;
		while (i < game->map_dim.y && j < game->map_dim.x)
		{
			player += is_elem(game->matrix[i][j], 'P');
			game->player_pos.x = j;
			game->player_pos.y = i;
			j++;
		}
		i++;
	}
	if (player > 1)
		return (ERROR_DUPLIC_PLAYER);
	if (player < 1)
		return (ERROR_NO_PLAYER);
	return (0);
}

int	check_exit(t_map	*game)
{
	int	exit;
	int	i;
	int	j;

	i = 0;
	exit = 0;
	while (game->matrix[i])
	{
		j = 0;
		while (game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
		{
			if (is_elem(game->matrix[i][j], 'E') == 1)
			{
				game->exit_pos.x = j;
				game->exit_pos.y = i;
				exit++;
			}
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (ERROR_EXIT);
	return (0);
}

void	player_current_pos(t_map	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_dim.y)
	{
		j = 0;
		while (j < game->map_dim.x)
		{
			if (game->matrix[i][j] == 'P')
			{
				break ;
			}
			j++;
		}
		if (game->matrix[i][j] == 'P')
		{
			break ;
		}
		i++;
	}
	game->player_pos.y = i;
	game->player_pos.x = j;
}
