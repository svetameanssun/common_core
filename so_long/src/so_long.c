#include "../include/so_long.h"

static void	ft_leaks(void)
{
	system("leaks -q so_long");
}

void	init_game(t_map *game)
{
	game->matrix = NULL;
	game->map_dim.x = 0;
	game->map_dim.y = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->coll_pos = NULL;
	game->n_collects = 0;
	game->n_collected = 0;
	game->moves = 0;
	game->mlx = NULL;
}

int main(int argc, char ** argv)
{
	t_map game;
	int exit_code;

	if (argc != 2)
	{
		manage_map_error(&game,ERROR_INPUT);
	}
	init_game(&game);
	check_map(argv[1], &game);
	show_window(&game);
}