#include "../include/so_long.h"


/*char **map_to_matrix(char *map_name)
{
    int lines_num;
    int fd;
    char **matrix;
    char *line;
    int i;

    line = NULL;
    printf("%s", line);
    lines_num = count_map_lines(map_name);
	printf("%d", lines_num);
    fd = open(map_name,O_RDONLY);

    while(i < lines_num)
    {
        line = ft_strjoin(line, get_next_line(fd));
        printf("%s", line);
        i++;
    }

    matrix = ft_split(line, '\n');
    return(matrix);
}*/

int valid_map(char * map_name, t_map *game)
{
	
	if (check_map_name(map_name) != 0)
	{	
		return(1);
	}
	printf("Name checked.\n");
	
	if (check_rectangular(game->matrix) != 0)
	{	
		return(2);
	}
	printf("Map rectangular.\n");
	if (check_chars(game->matrix) != 0)
	{	
		return(3);
	}
	printf("Characters checked.\n");

	if (check_walls(game->matrix) != 0)
	{	
		return(4);
	}
	printf("Perfect enclosure.\n");
	if (check_elem(game->matrix, 0, 0) != 0)
	{	
		return(5);
	}
	printf("Perfect ammount of elements.\n");
	return(0);
}

/*int main(int argc, char**argv)
{
	valid_map(argv[1]);
}*/