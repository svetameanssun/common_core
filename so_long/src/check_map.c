#include "../include/so_long.h"

void manage_error(t_map *game)
{
	ft_putstr("Error \n");
	if (game)
	{
		free_game(game);
	}
	exit(1);

}

void manage_game_error(t_map *game, int exit_code)
{
	if (exit_code == ERROR_MLX)
			write(2, "Error:\n Could not create MXL.\n", 31);
	
        free_game(game);
		exit(exit_code);
}

void manage_map_error(t_map *game, int exit_code)
{
		if (exit_code == ERROR_INPUT)
		    ft_putstr("Error:\n Invalid number of arguments\n");
		if (exit_code == ERROR_NO_PATH)
			ft_putstr("Error:\n Invalid path to exit\n");
        if (exit_code == ERROR_MAP_NAME)
		    ft_putstr("Error:\n Wrong map name.\n");
		if (exit_code == ERROR_EMPTY_FILE)
			ft_putstr("Error:\n The file is empty.\n");
        if (exit_code == ERROR_NO_RECT)
            ft_putstr("Error:\n Map is not rectangular.\n");
        if (exit_code == ERROR_FORBIDDEN_ELEM)
            ft_putstr("Error:\n Wrong elements in map.\n");
        if (exit_code == ERROR_NO_WALLS)
            ft_putstr("Error:\n Walls are not enclosed.\n");
        if (exit_code == ERROR_NO_PLAYER)
            ft_putstr("Error:\n No players.\n");
		if (exit_code == ERROR_DUPLIC_PLAYER)
			ft_putstr("Error:\n More than one player.\n");
		if (exit_code == ERROR_NO_ENEMY)
			ft_putstr("Error:\n Wrong enemy number.\n");
        if (exit_code == ERROR_NO_EXIT)
            ft_putstr("Error:\n Wrong exit or collect number.\n");
		if (exit_code == ERROR_DUPLIC_EXIT)
            ft_putstr("Error:\n More than one exit.\n");
		if (exit_code == ERROR_NO_COLLECTABLES)
            ft_putstr("Error:\n Wrong collect number.\n");
		if (exit_code == ERROR_MALLOC)
			ft_putstr("Error:\n Memory not allocated using malloc.\n");
		if (exit_code == ERROR_FD)
			ft_putstr("Error:\n Could not open file.\n");
        free_game(game);
		exit(exit_code);
}

int check_map(char * map_name, t_map *game)
{
	int error;

	error = 0;
	if (map_to_matrix(map_name, game) != error)
		manage_map_error(game, ERROR_EMPTY_FILE);
	printf("The file is not empty.\n");
	if (check_map_name(map_name) != error)
		manage_map_error(game, ERROR_MAP_NAME);
	printf("Name checked.\n");
	if (check_rectangular(game) != error)
		manage_map_error(game, ERROR_NO_RECT);
	printf("Map rectangular.\n");
	if (check_elements(game) != error)
		manage_map_error(game, ERROR_FORBIDDEN_ELEM);
	printf("All elements checked.\n");
	if (check_walls(game) != error)
		manage_map_error(game, ERROR_NO_WALLS);
	printf("Perfect enclosure.\n");
	if (check_player(game) != error)
	{
		error = check_player(game);
		manage_game_error(game,error);
	}
	if(check_enemy(game)!= error)
	{
		manage_map_error(game, ERROR_NO_ENEMY);
	}
	printf("Player and enemy present.\n");
	if (check_collect(game) != error)
		manage_map_error(game, ERROR_NO_COLLECTABLES);
	if (check_exit(game)!= error)
	{
		error = check_exit(game);
		manage_map_error(game, error);
	}
	printf("Right ammount of collect and exit.\n");
	if(floodfill(game) != 0)
		manage_map_error(game, ERROR_NO_PATH);
	return(0);
}


