//#include "get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

/*char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	fd_res;
	size_t	little_len;
	size_t	big_len;

	little_len = (ft_strlen((char *)little));
	big_len = (ft_strlen((char *)big));
	if (little_len == 0)
		return ((char *)big);
	fd_res = 0;
	while (fd_res + little_len <= len && fd_res < big_len)
	{
		if (ft_strncmp(big + fd_res, little, little_len) == 0)
			return ((char *)big + fd_res);
		fd_res++;
	}
	return (NULL);
}*/

int new_in_rem(char *rem)
{
	int i;

	i = 0;
	if (rem == NULL)
	{
		printf("remain is empty\n");
		return(0);
	}
	while(rem[i] != '\0')
	{
		if (rem[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_extract_line(char *dest, char *src)
{
	size_t	i;
	char	c;

	if(!src)
	{
		printf("SRC IS EMPTY IN EXTRACT_LINE\n");
		return (NULL);
	}
	
	i = 0;
	c = '\n';
	while(*src != c || src != NULL)
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
	size_t	fd_res;

	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	fd_res = 0;
	while (fd_res < ft_strlen(s1))
	{
		new[fd_res] = s1[fd_res];
		fd_res++;
	}
	while (fd_res < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new[fd_res] = s2[fd_res - ft_strlen(s1)];
		fd_res++;
	}
	new[fd_res] = '\0';
	return (new);
}

char *get_next_line(int fd)
{   
    static char *remaining;
	char *line = NULL;
	char *buffer;
	int fd_res;
	int i;
	int BUFFER_SIZE = 4; // DELETE THIS LINE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{	
		printf("MALLOC ERROR IN BUFFER\n");
		return (NULL);
	}
	
	fd_res = 1;
	i = 0;
    // read while there's stuff left to read
	while (*remaining +i == '\n' && fd_res > 0)//"remaining doesn't include a newline"
	{
		fd_res = read(fd, buffer, BUFFER_SIZE);
		
		buffer[BUFFER_SIZE] = '\0';
		remaining = malloc(sizeof(char)*(BUFFER_SIZE + 1));
		if(!remaining)
		{
		printf("ERROR MALLOC IN COPY_LINE\n");
		return (NULL);
		}
		if( fd_res < 0)
		{
			free(buffer);
			free(remaining);
			printf("BAD ERRROR\n");
			return (NULL);
		}
		//if fd_res == -1, then BAD ERROR, we must free everything, buffer and remaining, and return NULL
		
		//"strjoin add buffer to remaining:";
		ft_strjoin(remaining, buffer);
		i++;
        
	}
	free(buffer);
	//"put (extract) here a copy of the FIRST line from remaining";
    line = ft_extract_line(line, remaining);
	//remaining = "remaining (itself) but only after the line we extracted earlier or NULL if nothing left";
	//esa funcion tiene que hacer la copia nueva y liberar el str antiguo
	return (line);
}

int main(){
	int fd_reading = open("file_to_read.txt", O_RDONLY);
	if (fd_reading < 0)
	{
		printf("%s", "ERROR open");
		return (1);
	}
    printf("%s\n", get_next_line(fd_reading));
    close(fd_reading);
}
