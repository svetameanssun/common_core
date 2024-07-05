#include "../include/so_long.h"

int	check_exit_access(t_map *game)
{
	if (game->n_collects == 0)
	{
		write(1, "¡Enhorabuena! 🎮🏆\n", 23);
		free_game(game);
		exit(1);
	}
	if (game->n_collects != 0)
	{
		write(1, "Necesitas recoger todos los consumibles!\n", 41);
		return (1);
	}
	else
	{
		manage_error(game);
		return (0);
	}
}

void delete_candles(t_map * game)
{
	int i;

	i = 0;
	if (game->matrix[game->player.y][game->player.x] == 'C')
	{
		game->matrix[game->player.y][game->player.x] == '0';
		ft_displ_wall_floor(game);
		ft_displ_player(game);
		game->n_collects--;
		game->n_collected++;
	}
}

void collect_candles(t_map *game)
{
	if (game->matrix[game->images.player_right->instances->y / PIX]
		[game->images.player_right->instances->x / PIX] == 'c')
	{
		delete_candles(game);
		if (game->n_collects == 0)
		{
			game->images.exit->instances->enabled = false;
		}
	}
	if(game->matrix[game->images.player_right->instances->y / PIX]
		[game->images.player_right->instances->x / PIX] == 'E')
	{
		check_exit_access(game);
		{
			if (game->n_collects == 0)
				mlx_close_window(game->mlx);
		}
	}
}