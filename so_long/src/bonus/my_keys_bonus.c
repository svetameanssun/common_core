/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_keys_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:05:46 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 17:46:58 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	key_w(t_map *game)
{
	if (game->matrix[game->player_pos.y - 1][game->player_pos.x] != '1')
	{
		game->images.player_right_down->instances[0].y -= PIX;
		game->images.player_left_down->instances[0].y -= PIX;
		game->images.player_left_up->instances[0].y -= PIX;
		game->images.player_right_up->instances[0].y -= PIX;
		game->images.player_left_up->enabled = false;
		game->images.player_right_down->enabled = false;
		game->images.player_right_up->enabled = true;
		game->images.player_left_down->enabled = false;
		game->player_pos.y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	key_d(t_map *game)
{
	if (game->matrix[game->player_pos.y][game->player_pos.x + 1] != '1')
	{
		game->images.player_right_down->instances[0].x += PIX;
		game->images.player_left_down->instances[0].x += PIX;
		game->images.player_left_up->instances[0].x += PIX;
		game->images.player_right_up->instances[0].x += PIX;
		game->images.player_right_down->enabled = true;
		game->images.player_left_up->enabled = false;
		game->images.player_left_down->enabled = false;
		game->images.player_right_up->enabled = false;
		game->player_pos.x++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	key_s(t_map *game)
{
	if (game->matrix[game->player_pos.y + 1][game->player_pos.x] != '1')
	{
		game->images.player_right_down->instances[0].y += PIX;
		game->images.player_left_down->instances[0].y += PIX;
		game->images.player_left_up->instances[0].y += PIX;
		game->images.player_right_up->instances[0].y += PIX;
		game->images.player_left_down->enabled = true;
		game->images.player_left_up->enabled = false;
		game->images.player_right_down->enabled = false;
		game->images.player_right_up->enabled = false;
		game->player_pos.y++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}

void	key_a(t_map *game)
{
	if (game->matrix[game->player_pos.y][game->player_pos.x - 1] != '1')
	{
		game->images.player_right_down->instances[0].x -= PIX;
		game->images.player_left_down->instances[0].x -= PIX;
		game->images.player_left_up->instances[0].x -= PIX;
		game->images.player_right_up->instances[0].x -= PIX;
		game->images.player_right_up->enabled = false;
		game->images.player_right_down->enabled = false;
		game->images.player_left_down->enabled = false;
		game->images.player_left_up->enabled = true;
		game->player_pos.x--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}
