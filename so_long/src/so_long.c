#include "../include/so_long.h"




void	init_game(t_map *game)
{
	game->matrix = NULL;
	game->map_dim.x = 0;
	game->map_dim.y = 0;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->exit_pos.x = 0;
	game->exit_pos.y = 0;
	//game->coll_pos = NULL;
	game->enemies_pos = NULL;
	game->n_collects = 0;
	game->n_collected = 0;
	game->n_enemies = 0;
	game->moves = 0;
	game->movmnts = NULL;
	game->mlx = NULL;
}

int main(int argc, char ** argv)
{
	t_map game;
	int exit_code;

	if (argc != 2)
		manage_prog_error(&game,ERROR_INPUT);
	init_game(&game);
	check_map(argv[1], &game);
	show_window(&game);
	mlx_key_hook(game.mlx, &my_keyhook, &game);
	mlx_loop(game.mlx);
	delete_img(&game);
	mlx_terminate(game.mlx);
	free_game(&game);
	

}