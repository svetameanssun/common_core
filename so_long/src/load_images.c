/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:25:34 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/12 16:28:35 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_textures(t_map	*game)
{
	game->textures.floor = mlx_load_png("./imgs/floor.png");
	game->textures.wall = mlx_load_png("./imgs/wall.png");
	game->textures.exit_closed = mlx_load_png("./imgs/exit_closed.png");
	game->textures.exit_opened = mlx_load_png("./imgs/exit_opened.png");
	game->textures.player_left_down = mlx_load_png("./imgs/vasilisa_dl.png");
	game->textures.player_right_down = mlx_load_png("./imgs/vasilisa_dr.png");
	game->textures.player_left_up = mlx_load_png("./imgs/vasilisa_ul.png");
	game->textures.player_right_up = mlx_load_png("./imgs/vasilisa_ur.png");
	game->textures.enemy_left = mlx_load_png("./imgs/enemy_l.png");
	game->textures.enemy_right = mlx_load_png("./imgs/enemy_r.png");
	game->textures.collect = mlx_load_png("./imgs/candle.png");
}

void	textures_to_img(t_map *game)
{
	game->images.floor = mlx_texture_to_image(game->mlx, \
	game->textures.floor);
	game->images.wall = mlx_texture_to_image(game->mlx, \
	game->textures.wall);
	game->images.exit_closed = mlx_texture_to_image(game->mlx, \
	game->textures.exit_closed);
	game->images.exit_opened = mlx_texture_to_image(game->mlx, \
	game->textures.exit_opened);
	game->images.player_left_down = mlx_texture_to_image(game->mlx, \
	game->textures.player_left_down);
	game->images.player_right_down = mlx_texture_to_image(game->mlx, \
	game->textures.player_right_down);
	game->images.player_left_up = mlx_texture_to_image(game->mlx, \
	game->textures.player_left_up);
	game->images.player_right_up = mlx_texture_to_image(game->mlx, \
	game->textures.player_right_up);
	game->images.enemy_left = mlx_texture_to_image(game->mlx, \
	game->textures.enemy_left);
	game->images.enemy_right = mlx_texture_to_image(game->mlx, \
	game->textures.enemy_right);
	game->images.collect = mlx_texture_to_image(game->mlx, \
	game->textures.collect);
}

void	create_playwindow(t_map *game)
{
	game->mlx = mlx_init(game->map_dim.x * PIX, \
	game->map_dim.y * PIX, "Vasilisa", false);
	if (!game->mlx)
		manage_prog_error(game, ERROR_MLX);
}
