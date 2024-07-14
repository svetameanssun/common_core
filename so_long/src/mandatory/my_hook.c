/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:23:10 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/14 14:53:46 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	all_moves(mlx_key_data_t k, t_map	*game)
{
	if ((k.key == MLX_KEY_W || k.key == MLX_KEY_UP) && k.action == MLX_PRESS)
	{
		key_w(game);
		update_game(game);
	}
	if ((k.key == MLX_KEY_S || k.key == MLX_KEY_DOWN) && k.action == MLX_PRESS)
	{
		key_s(game);
		update_game(game);
	}
	if ((k.key == MLX_KEY_D || k.key == MLX_KEY_RIGHT) && k.action == MLX_PRESS)
	{
		key_d(game);
		update_game(game);
	}
	if ((k.key == MLX_KEY_A || k.key == MLX_KEY_LEFT) && k.action == MLX_PRESS)
	{
		key_a(game);
		update_game(game);
	}
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		return ;
	}
}

void	my_keyhook(mlx_key_data_t k, void	*param)
{
	t_map	*game;
	char	*moves;
	char	*aux;
	int		x;
	int		y;

	game = (t_map *) param;
	x = (game->map_dim.x - 2) * PIX + 50;
	y = (game->map_dim.y - 2) * PIX + 120;
	all_moves(k, game);
	moves = ft_itoa(game->moves);
	aux = ft_strjoin("MOVES:\n", moves);
	mlx_delete_image(game->mlx, game->movmnts);
	game->movmnts = mlx_put_string(game->mlx, aux, x, y);
	free(moves);
	free(aux);
}
