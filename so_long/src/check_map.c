#include "../include/so_long.h"

int check_map(char * map_name)
{
	int map_fd;

	map_fd = open(map_name, O_RDONLY, 644);
	if (check_map_name(map_name) != 0)
		return(1);
	if (check_chars(map_name, map_fd) != 0)
		return(2);
	if (check_walls(map_name) != 0)
		return(3);
	if (check_deadends(map_name) != 0)
		return(4);
	
}
int main()
{}