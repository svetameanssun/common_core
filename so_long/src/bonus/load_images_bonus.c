/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:25:34 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 20:47:53 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_texture(t_map	*game, mlx_texture_t **txt, char *str)
{
	*txt = mlx_load_png(str);
	if (!*txt)
	{
		manage_prog_error(game, ERROR_LOC);
	}
}

void	load_textures(t_map	*game)
{
	check_texture(game, &game->textures.floor, "./imgs/floor.png");
	check_texture(game, &game->textures.wall, "./imgs/wall.png");
	check_texture(game, &game->textures.exit_closed, "./imgs/exit_closed.png");
	check_texture(game, &game->textures.exit_opened,
		"./imgs/exit_opened.png");
	check_texture(game, &game->textures.player_left_down,
		"./imgs/vasilisa_dl.png");
	check_texture(game, &game->textures.player_right_down,
		"./imgs/vasilisa_dr.png");
	check_texture(game, &game->textures.player_left_up,
		"./imgs/vasilisa_ul.png");
	check_texture(game, &game->textures.player_right_up,
		"./imgs/vasilisa_ur.png");
	check_texture(game, &game->textures.enemy_left, "./imgs/enemy_l.png");
	check_texture(game, &game->textures.enemy_right, "./imgs/enemy_r.png");
	check_texture(game, &game->textures.collect, "./imgs/candle.png");
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
	game->map_dim.y * PIX, "Vasilisa", true);
	if (!game->mlx)
		manage_prog_error(game, ERROR_MLX);
}
