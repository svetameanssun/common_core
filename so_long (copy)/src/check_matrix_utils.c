#include "../include/so_long.h"

int is_elem(int c, int elem)
{
    int res;

    res = 0;
    if (c == elem)
        return(1);
    return(0);
}

size_t	ft_strlen_sl(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

int count_map_lines(char * map_name)
{
	int count;
	char *str;
    int fd;

	fd = open(map_name, O_RDONLY);
    if (fd < 0)
        manage_prog_error(NULL, ERROR_FD);
	str = get_next_line(fd);
	free(str);
    count = 0;
    while(str)
    {
        str = get_next_line(fd);
		free(str);
		count++;
    }
    close(fd);
    return(count);
}

int check_map_name(char *map_name)
{
    int i;
    int len;
    int res;

    i = 0;
    len = ft_strlen(map_name);
    if (len < 4)
		return (ERROR_MAP_NAME);
    res = ft_strncmp(map_name + (len - 4), ".ber", 4);
    if (res != 0)
        return(ERROR_MAP_NAME);
    return(0);
}
