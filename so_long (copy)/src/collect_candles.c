#include "../include/so_long.h"

int	check_exit_access(t_map *game)
{
	if (game->n_collects == 0)
	{
		ft_putchar("Congratulations! 🎮🏆\n");
		free_game(game);
		exit(1);
	}
	if (game->n_collects != 0)
	{
		ft_putchar("You need to collect all the collectables\n");
		return(1);
	}
	else
	{
		manage_error(game);
		return (0);
	}
}

/*void delete_candles(t_map * game)
{
	int i;

	i = 0;
	if (game->matrix[game->player.y][game->player.x] == 'C')
	{
		game->matrix[game->player.y][game->player.x] = '0';
		//show_images(game);

		//ft_displ_wall_floor(game);
		//ft_displ_player(game);
		game->n_collects--;
		game->n_collected++;
	}
}*/

void collect_candles(t_map *game)
{
	if (game->matrix[game->player.y][game->player.x] == 'C')
	{
		game->matrix[game->player.y][game->player.x] = '0';
		//if (game->matrix[game->player.y][game->player.x] == '0')
		printf("%c\n", game->matrix[game->player.y][game->player.x]);
		//show_images(game);

		//ft_displ_wall_floor(game);
		//ft_displ_player(game);
		game->n_collects--;
		game->n_collected++;
		//delete_candles(game);
		if (game->n_collects == 0)
		{
			game->images.exit->instances->enabled = false;
		}
	}
	/*if(game->matrix[game->images.player_right->instances->y / PIX]
		[game->images.player_right->instances->x / PIX] == 'E')*/
	if (game->matrix[game->player.y][game->player.x] == 'E')
	{
		check_exit_access(game);
		if (game->n_collects == 0)
			mlx_close_window(game->mlx);
	}
}