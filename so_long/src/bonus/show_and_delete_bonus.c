/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_and_delete_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:25:47 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 21:03:38 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	delete_textures(t_map *game)
{
	mlx_delete_texture(game->textures.floor);
	mlx_delete_texture(game->textures.wall);
	mlx_delete_texture(game->textures.exit_closed);
	mlx_delete_texture(game->textures.exit_opened);
	mlx_delete_texture(game->textures.player_left_down);
	mlx_delete_texture(game->textures.player_right_down);
	mlx_delete_texture(game->textures.player_left_up);
	mlx_delete_texture(game->textures.player_right_up);
	mlx_delete_texture(game->textures.enemy_left);
	mlx_delete_texture(game->textures.enemy_right);
	mlx_delete_texture(game->textures.collect);
}

void	delete_img(t_map *game)
{
	mlx_delete_image(game->mlx, game->images.floor);
	mlx_delete_image(game->mlx, game->images.wall);
	mlx_delete_image(game->mlx, game->images.exit_closed);
	mlx_delete_image(game->mlx, game->images.exit_opened);
	mlx_delete_image(game->mlx, game->images.player_left_down);
	mlx_delete_image(game->mlx, game->images.player_right_down);
	mlx_delete_image(game->mlx, game->images.player_left_up);
	mlx_delete_image(game->mlx, game->images.player_right_up);
	mlx_delete_image(game->mlx, game->images.enemy_left);
	mlx_delete_image(game->mlx, game->images.enemy_right);
	mlx_delete_image(game->mlx, game->images.collect);
}

void	show_map(t_map	*game)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			load_elem(game, i, j, '0');
			if (game->matrix[j][i] == '1')
				load_elem(game, i, j, '1');
			else if (game->matrix[j][i] == 'E')
				load_elem(game, i, j, 'E');
			else if (game->matrix[j][i] == 'C')
				load_elem(game, i, j, 'C');
			else if (game->matrix[j][i] == 'N')
				load_elem(game, i, j, 'N');
			i++;
		}
		j++;
	}
	load_elem(game, game->player_pos.x, game->player_pos.y, 'P');
	update_enemy(game);
}

int32_t	show_window(t_map *game)
{
	create_playwindow(game);
	load_textures(game);
	textures_to_img(game);
	delete_textures(game);
	show_map(game);
	return (EXIT_SUCCESS);
}
