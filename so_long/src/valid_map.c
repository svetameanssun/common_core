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





int valid_map(char * map_name)
{
	char ** map_matrix;

	map_matrix = map_to_matrix(map_name);
	
	if (check_map_name(map_name) != 0)
	{	
		printf("Error in map_name.\n");
		return(1);
	}
	printf("Name checked.\n");
	
	if (check_rectangular(map_matrix) != 0)
	{	
		printf("Map is not rectangular.\n");
		return(2);
	}
	printf("Map rectangular.\n");
	if (check_chars(map_matrix) != 0)
	{	
		printf("Wrong characters in map.\n");
		return(3);
	}
	printf("Characters checked.\n");

	if (check_walls(map_matrix) != 0)
	{	
		printf("Walls are not enclosed.\n");
		return(4);
	}
	printf("Perfect enclosure.\n");
	if (check_elem(map_matrix, 0) != 0)
	{	
		printf("Wrong elements.\n");
		return(5);
	}
	printf("Perfect ammount of elements.\n");

	return(0);
}

int main(int argc, char**argv)
{
	valid_map(argv[1]);
}