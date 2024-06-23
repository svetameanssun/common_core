#include "../include/so_long.h"

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
		    write(2, "Error:\n Invalid number of arguments\n", 36);
		if (exit_code == ERROR_NO_PATH)
			write(2, "Error:\n Invalid path to exit\n", 29);
        if (exit_code == ERROR_MAP_NAME)
		    write(2, "Error:\n Wrong map name.\n", 25);
		if (exit_code == ERROR_EMPTY_FILE)
			write(2, "Error:\n The file is empty.\n", 28);
        if (exit_code == ERROR_NO_RECT)
            write(2, "Error:\n Map is not rectangular.\n", 33);
        if (exit_code == ERROR_FORBIDDEN_ELEM)
            write(2, "Error:\n Wrong elements in map.\n", 32);
        if (exit_code == ERROR_NO_WALLS)
            write(2, "Error:\n Walls are not enclosed.\n", 33);
        if (exit_code == ERROR_NO_PLAYER)
            write(2, "Error:\n Wrong player or enemy number.\n", 39);
        if (exit_code == ERROR_NO_EXIT)
            write(2, "Error:\n Wrong exit or collect number.\n", 39);
		if (exit_code == ERROR_MALLOC)
			write(2, "Error:\n Memory not allocated using malloc.\n", 44);
		if (exit_code == ERROR_FD)
			write(2, "Error:\n Could not open file.\n", 30);
        free_game(game);
		exit(exit_code);
}

int check_map(char * map_name, t_map *game)
{
	if (map_to_matrix(map_name, game) != 0)
		manage_map_error(game, ERROR_EMPTY_FILE);
	printf("The file is not empty.\n");
	if (check_map_name(map_name) != 0)
		manage_map_error(game, ERROR_MAP_NAME);
	printf("Name checked.\n");
	if (check_rectangular(game) != 0)
		manage_map_error(game, ERROR_NO_RECT);
	printf("Map rectangular.\n");
	if (check_elements(game) != 0)
		manage_map_error(game, ERROR_FORBIDDEN_ELEM);
	printf("All elements checked.\n");
	if (check_walls(game) != 0)
		manage_map_error(game, ERROR_NO_WALLS);
	printf("Perfect enclosure.\n");
	if (check_characters(game) != 0)	
		manage_map_error(game, ERROR_NO_PLAYER);
	printf("Player and enemy present.\n");
	if (check_collect(game) != 0)
		manage_map_error(game, ERROR_NO_EXIT);
	printf("Right ammount of collect and exit.\n");
	if(floodfill(game) != 0)
		manage_map_error(game, ERROR_NO_PATH);
	return(0);
}


