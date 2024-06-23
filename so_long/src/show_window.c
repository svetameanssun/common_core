#include "../include/so_long.h"

void	load_textures(t_map	*game)
{
	game->textures.floor = mlx_load_png("./assets/floor.png");
	game->textures.wall = mlx_load_png("./assets/wall.png");
	game->textures.exit = mlx_load_png("./assets/izbushka.png");
	game->textures.player_r = mlx_load_png("./assets/vasilisa_right.png");
	game->textures.enemy_l = mlx_load_png("./assets/baba_yaga_left.png");
	game->textures.collect = mlx_load_png("./assets/candle.png");
}

void	textures_to_img(t_map *game)
{
	game->images.floor = mlx_texture_to_image(game->mlx, game->textures.floor);
	game->images.wall = mlx_texture_to_image(game->mlx, game->textures.wall);
	game->images.exit = mlx_texture_to_image(game->mlx, game->textures.exit);
	game->images.player_right = mlx_texture_to_image(game->mlx, game->textures.player_r);
	game->images.enemy_left= mlx_texture_to_image(game->mlx, game->textures.enemy_l);
	game->images.collect = mlx_texture_to_image(game->mlx, game->textures.collect);
}

void	create_playwindow(t_map *game)
{
	game->mlx = mlx_init(game->map_dim.x * PIX, game->map_dim.y * PIX, "Vasilisa", false);
	if (!game->mlx)
		manage_game_error(game, ERROR_MLX);
}

void	delete_textures(t_map *game)
{
	mlx_delete_texture(game->textures.floor);
	mlx_delete_texture(game->textures.wall);
	mlx_delete_texture(game->textures.exit);
	mlx_delete_texture(game->textures.player_r);
	mlx_delete_texture(game->textures.enemy_l);
	mlx_delete_texture(game->textures.collect);
}

int32_t	show_window(t_map *data)
{
	create_playwindow(data);
	load_textures(data);
	textures_to_img(data);
	delete_textures(data);
	show_images(data);
	return (EXIT_SUCCESS);
}
