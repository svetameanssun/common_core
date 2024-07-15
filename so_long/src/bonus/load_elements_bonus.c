/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:10:53 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 17:46:36 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

mlx_image_t	*get_image(t_map *game, mlx_image_t *img, char symbol)
{
	if (symbol == '1')
		img = game->images.wall;
	if (symbol == '0')
		img = game->images.floor;
	if (symbol == 'C')
		img = game->images.collect;
	if (symbol == 'P')
		img = game->images.player_right_down;
	if (symbol == '2')
		img = game->images.player_left_down;
	if (symbol == '3')
		img = game->images.player_right_up;
	if (symbol == '4')
		img = game->images.player_left_up;
	if (symbol == 'E')
		img = game->images.exit_closed;
	if (symbol == 'D')
		img = game->images.exit_opened;
	if (symbol == 'N')
		img = game->images.enemy_left;
	if (symbol == 'R')
		img = game->images.enemy_right;
	if (!img)
		manage_prog_error(game, ERROR_MLX);
	return (img);
}

void	load_players(t_map *game, mlx_image_t *img, int x, int y)
{
	img = get_image(game, img, 'P');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	img = get_image(game, img, '2');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	img = get_image(game, img, '3');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	img = get_image(game, img, '4');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	game->images.player_left_up->enabled = false;
	game->images.player_left_down->enabled = false;
	game->images.player_right_up->enabled = false;
}

void	load_exits(t_map *game, mlx_image_t *img, int x, int y)
{
	img = get_image(game, img, 'D');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	img = get_image(game, img, 'E');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	game->images.exit_opened->enabled = false;
}

void	load_enemies(t_map *game, mlx_image_t *img, int x, int y)
{
	img = get_image(game, img, 'N');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	img = get_image(game, img, 'R');
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
}

void	load_elem(t_map *game, int x, int y, char symbol)
{
	mlx_image_t	*img;

	img = NULL;
	if (symbol == 'C' || symbol == '0' || symbol == '1')
	{
		img = get_image(game, img, symbol);
		mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
	}
	else if (symbol == 'P')
		load_players(game, img, x, y);
	else if (symbol == 'E')
		load_exits(game, img, x, y);
	else if (symbol == 'N')
		load_enemies(game, img, x, y);
}
