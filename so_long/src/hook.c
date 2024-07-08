#include "../include/so_long.h"

void key_s(t_map *game)
{
	if (game->matrix[game->player_pos.y + 1][game->player_pos.x] != '1')
	{
		game->images.player_right->instances[0].y += PIX;
		game->player_pos.y++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void key_w(t_map *game)
{
	
	if(game->matrix[game->player_pos.y - 1][game->player_pos.x] != '1')
	{
		
		game->images.player_right->instances[0].y -= PIX;
		game->player_pos.y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}
	

void key_a(t_map *game)
{
	if(game->matrix[game->player_pos.y][game->player_pos.x - 1] != '1')
	{
		game->images.player_right->instances[0].x -= PIX;
		game->player_pos.x--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void key_d(t_map * game)
{
	if(game->matrix[game->player_pos.y][game->player_pos.x + 1] != '1')
	{
		game->images.player_right->instances[0].x += PIX;
		game->player_pos.x++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map *game;

	game = (t_map *) param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS ) 
		key_w(game);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		key_s(game);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		key_d(game);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		key_a(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_game(game);
		free(game);
		exit(1);
	}
	collect_candles(game);
}