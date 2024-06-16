#include "../include/so_long.h"

int manage_errors(int exit_code, t_map *game)
{

    if (exit_code == 1)
    {
		write(2, "Error in map_name.\n", 20);
        free_game(game);
    }
    if (exit_code == 2)
	{	
        write(2, "Map is not rectangular.\n", 25);
        free_game(game);
    }
    if (exit_code == 3)
	{	
        write(2, "Wrong characters in map.\n", 26);
        free_game(game);
    }
    if (exit_code == 4)
	{	
        write(2, "Walls are not enclosed.\n", 25);
        free_game(game);
    }
    if (exit_code == 5)
	{	
        write(2, "Wrong elements.\n", 17);
        free_game(game);
    }
    return(exit_code);
}

