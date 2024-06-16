#include "../include/so_long.h"

void	set_game(t_map *game)
{
	game->mlx = NULL;
	game->matrix = NULL;
	game->images = NULL;
	game->moves = 0;
}

int main(int argc, char ** argv)
{
	t_map *game;
	int valid_matrix;

	game = (t_map*)malloc(sizeof(t_map));
	set_game(game);
	map_to_matrix(argv[1], game);
	valid_matrix = valid_map(argv[1], game);
	manage_errors(valid_matrix, game);
	
	


}