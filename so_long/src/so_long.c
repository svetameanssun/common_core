/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:25:52 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/10 17:47:06 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_map *game)
{
	game->matrix = NULL;
	game->map_dim.x = 0;
	game->map_dim.y = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->exit_pos.x = 0;
	game->exit_pos.y = 0;
	game->n_collects = 0;
	game->n_collected = 0;
	game->n_enemies = 0;
	game->moves = 0;
	game->movmnts = NULL;
	game->mlx = NULL;
}

int main(int argc, char ** argv)
{
	t_map game;

	if (argc != 2)
		manage_prog_error(&game,ERROR_INPUT);
	init_game(&game);
	check_map(argv[1], &game);
	show_window(&game);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	delete_img(&game);
	mlx_terminate(game.mlx);
	free_if_game(&game);
}