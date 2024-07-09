#include "../include/so_long.h"

void key_s(t_map *game)
{
	if (game->matrix[game->player_pos.y + 1][game->player_pos.x] != '1')
	{
		
		game->images.player_right_down->instances[0].y += PIX;
		game->player_pos.y++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void key_w(t_map *game)
{
	
	if(game->matrix[game->player_pos.y - 1][game->player_pos.x] != '1')
	{
		
		game->images.player_right_down->instances[0].y -= PIX;
		game->player_pos.y--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}
}
	

void key_a(t_map *game)
{
	if(game->matrix[game->player_pos.y][game->player_pos.x - 1] != '1')
	{
		game->images.player_right_down->instances[0].x -= PIX;
		game->player_pos.x--;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void key_d(t_map * game)
{
	if(game->matrix[game->player_pos.y][game->player_pos.x + 1] != '1')
	{
		
		game->images.player_right_down->instances[0].x += PIX;
		game->player_pos.x++;
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
	}

}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map *game;
	char *moves;
	char *aux;

	game = (t_map *) param;
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS ) 
	{	key_w(game);
		update_game(game);
	}
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
	{	key_s(game);
		update_game(game);
	}
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
	{	key_d(game);
		update_game(game);
	}
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
	{	key_a(game);
		update_game(game);
	}
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		free_game(game);
		free(game);
		exit(1);
	}
	moves = ft_itoa(game->moves);
	aux = ft_strjoin("MOVES:\n", moves);
	mlx_delete_image(game->mlx, game->movmnts);
	game->movmnts = mlx_put_string(game->mlx, aux, (game->map_dim.x - 2) * PIX + 50, (game->map_dim.y - 2) * PIX + 120);
	free(moves);
	free(aux);
}
