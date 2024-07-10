#include "../include/so_long.h"

void	update_game(t_map *game)
{
	update_enemy(game);

	if (game->matrix[game->player_pos.y][game->player_pos.x] == 'C')
	{
		update_collectables(game);
		ft_printf("One more candle!\n");
	}
	if (game->matrix[game->player_pos.y][game->player_pos.x] == 'N')
	{
		ft_printf("Baba Yaga! Run away!\n");
		mlx_close_window(game->mlx);
	}
	if (game->matrix[game->player_pos.y][game->player_pos.x] == 'E')
	{
		if (game->n_collects == 0)
		{
			ft_printf("Time to go home, Vasilisa!\n");
			mlx_close_window(game->mlx);
		}
		else
			ft_printf("Go get more candles!\n");
	}
	
}

void	update_enemy(t_map *game)
{
	int	i;

	i = 0;
	
	while (i < game->n_enemies)
	{
		if (game->player_pos.x * PIX < game->images.enemy_left->instances[i].x)
		{
			game->images.enemy_left->instances[i].enabled = true;
			game->images.enemy_right->instances[i].enabled = false;
		}
		else
		{
			game->images.enemy_left->instances[i].enabled = false;
			game->images.enemy_right->instances[i].enabled = true;
		}

		i++;
	}
	return;
}


void	update_collectables(t_map *game)
{
	int	i;

	i = 0;
	
	while (game->n_collects != 0)
	{
		if (game->player_pos.x * PIX == game->images.collect->instances[i].x
			&& game->player_pos.y * PIX == game->images.collect->instances[i].y)
		{
			game->images.collect->instances[i].enabled = false;
			game->matrix[game->player_pos.y][game->player_pos.x] = '0';
			game->n_collects--;
			if(game->n_collects == 0)
			{
				ft_printf("You got all the candles.\nTime to go home, Vasilisa!\n");
				game->images.exit_opened->enabled = true;
				game->images.exit_closed->enabled = false;
			}
			return ;
		}
		i++;
	}
}
