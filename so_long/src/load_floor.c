#include "../include/so_long.h"

/*void	load_floor(t_map	*game, int i, int j)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("./assets/floor.png");
	if (!floor)
		write(2, "error", 6);
	game->images->floor = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	if (!game->images->floor)
		write(2, "error", 6);
	mlx_image_to_window(game->mlx, game->images->floor, i * PIX, j * PIX);
	if (mlx_image_to_window(game->mlx, \
		game->images->floor, i * PIX, j * PIX) < 0)
		write(2, "error", 6);
}*/