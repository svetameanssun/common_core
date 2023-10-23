#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*extract_line(char *dest, char *src)
{
	size_t	i;
	char	c;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if(!dest)
		return ("ERROR MALLOC IN COPY_LINE");
	i = 0;
	c = '\n';
	while(src[i] != c)
	{
		
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char *get_next_line(int fd)
{   
    static char *remaining = NULL;
	char *buffer;
    char *line;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return ("MALLOC ERROR IN BUFFER");

	int i;
	i = 1;
    // read while there's stuff left to read
	while (("remaining doesn't include a newline") && i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		//if i == -1, then BAD ERROR, we must free everything, buffer and remaining, and return NULL
		if( i == -1)
		{
			free(buffer);
			free(remaining);
			return (NULL);
		}
		
		"strjoin add buffer to remaining:";
		ft_strjoin(remaining, buffer);
        
	}
	free(buffer);
	"put (extract) here a copy of the FIRST line from remaining";
    line = copy_line(remaining);
	remaining = "remaining (itself) but only after the line we extracted earlier or NULL if nothing left";
	//esa funcion tiene que hacer la copia nueva y liberar el str antiguo
	return (line);
}

/*int main(){
	int fd_reading = open("file_to_read.txt", O_RDONLY);
	if (fd_reading < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}
    printf("%s\n", get_next_line(fd_reading));
    close(fd_reading);
}*/
