#include "../include/so_long.h"

int	check_exit_access(t_map *game)
{
	if (game->n_collects == 0)
	{
		ft_putstr("Congratulations! 🎮🏆\n");
		free_if_game(game);
		exit(1);
	}
	if (game->n_collects != 0)
	{
		ft_putstr("You need to collect all the candles\n");
		return(1);
	}
	else
	{
		free_if_game(game);
		return (0);
	}
}

void	delete_candles(t_map *game)
{
	int	i;

	i = 0;
	if (game->matrix[game->player_pos.y][game->player_pos.x] == 'C')
	{
		game->images.floor->instances[game->player_pos.y].enabled = false;
		game->matrix[game->player_pos.y][game->player_pos.x] = '0';
		
		game->n_collects--;
	}
}

void	collect_candles(t_map *game)
{

	//delete_candles(game);

	if (game->n_collects == 0)
	{
		game->images.exit->instances->enabled = false;
		load_elem(game, game->exit_pos.y, game->exit_pos.x, 'E');
	}
	if (game->matrix[game->images.player_right->instances->y / PIX]
		[game->images.player_right->instances->x / PIX] == 'E')
	{
		check_exit(game);
		if (game->n_collects == 0)
			mlx_close_window(game->mlx);
	}
}


