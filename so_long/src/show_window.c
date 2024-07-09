#include "../include/so_long.h"

void	load_textures(t_map	*game)
{
	game->textures.floor = mlx_load_png("./assets/floor_200.png");
	game->textures.wall = mlx_load_png("./assets/wall_200.png");

	game->textures.exit_closed = mlx_load_png("./assets/izbushka_closed_200.png");
	game->textures.exit_opened = mlx_load_png("./assets/izbushka_opened_200.png");

	game->textures.player_left_down = mlx_load_png("./assets/vasilisa_down_left_200.png");
	game->textures.player_right_down = mlx_load_png("./assets/vasilisa_down_right_200.png");
	game->textures.player_left_up = mlx_load_png("./assets/vasilisa_up_left_200.png");
	game->textures.player_right_up = mlx_load_png("./assets/vasilisa_up_right_200.png");

	game->textures.enemy_left = mlx_load_png("./assets/baba_yaga_left_200.png");
	game->textures.enemy_right = mlx_load_png("./assets/baba_yaga_right_200.png");
	game->textures.collect = mlx_load_png("./assets/candle_200.png");
}

void	textures_to_img(t_map *game)
{
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);

	game->images.exit_closed = mlx_texture_to_image(game->mlx, game->textures.exit_closed);
	game->images.exit_opened = mlx_texture_to_image(game->mlx, game->textures.exit_opened);

	game->images.player_left_down = mlx_texture_to_image(game->mlx, game->textures.player_left_down);
	game->images.player_right_down = mlx_texture_to_image(game->mlx, game->textures.player_right_down);
	game->images.player_left_up = mlx_texture_to_image(game->mlx, game->textures.player_left_up);
	game->images.player_right_up = mlx_texture_to_image(game->mlx, game->textures.player_right_up);

	game->images.enemy_left= mlx_texture_to_image(game->mlx, game->textures.enemy_left);
	game->images.enemy_right= mlx_texture_to_image(game->mlx, game->textures.enemy_right);
	game->images.collect = mlx_texture_to_image(game->mlx, game->textures.collect);
}

void	create_playwindow(t_map *game)
{
	game->mlx = mlx_init(game->map_dim.x * PIX, game->map_dim.y * PIX, "Vasilisa", false);
	if (!game->mlx)
		manage_prog_error(game, ERROR_MLX);
}

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

int32_t	show_window(t_map *game)
{
	create_playwindow(game);
	load_textures(game);
	textures_to_img(game);
	delete_textures(game);
	show_map(game);
	return (EXIT_SUCCESS);
}
