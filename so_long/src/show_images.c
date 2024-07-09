#include "../include/so_long.h"


mlx_image_t	*get_image(t_map *game, char symbol)
{
	mlx_image_t	*img;

	if (symbol == '1')
		img = game->images.wall;
	if (symbol == '0')
		img = game->images.floor;
	if (symbol == 'C')
		img = game->images.collect;
	if (symbol == 'P')
		img = game->images.player_right_down;
	if (symbol == '2')
		img = game->images.player_left_down;
	if (symbol == '3')
		img = game->images.player_right_up;
	if (symbol == '4')
		img = game->images.player_left_up;
	if (symbol == 'E')
		img = game->images.exit_closed;
	if (symbol == 'D')
		img = game->images.exit_opened;
	if (symbol == 'N')
		img = game->images.enemy_left;
	if (symbol == 'R')
		img = game->images.enemy_right;
	if (!img)
		manage_prog_error(game, ERROR_MLX);
	return (img);
}


void load_elem(t_map *game, int x, int y, char symbol)
{
	mlx_image_t	*img;

	img = get_image(game, symbol);
	mlx_image_to_window(game->mlx, img, x * PIX, y * PIX);
}

void	show_map(t_map	*game)
{
	mlx_image_t	*img;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (game->matrix[j])
	{
		i = 0;
		while (game->matrix[j][i] != '\n' && game->matrix[j][i] != '\0')
		{
			load_elem(game, i, j, '0');
			if (game->matrix[j][i] == '1')
				load_elem(game, i, j, '1');
			else if (game->matrix[j][i] == 'E')
				load_elem(game, i, j, 'E');
			else if (game->matrix[j][i] == 'C')
				load_elem(game, i, j, 'C');
			else if (game->matrix[j][i] == 'N')
				load_elem(game, i, j, 'N');
			i++;
		}
		j++;
	}
	load_elem(game, game->player_pos.x, game->player_pos.y, 'P');
}
