#include "../include/so_long.h"

int	check_nl_escape(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char **file_to_marix(int fd)
{
    char **matrix;
    char *buffer;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    
    while(!check_nl_escape())

    return(matrix);
}

char	*read_all(int fd, char *str)
{
	char	*buffer;
	int		fd_read;

	fd_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!check_nl_escape(str) && fd_read != 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[fd_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}



int check_chars(char *map_name, int fd)
{
    
    
}