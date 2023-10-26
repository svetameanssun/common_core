# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int BUFFER_SIZE = 4;

/*size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
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

char	*copy_str(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i]))
		{
			dest[i] = src[i];
			printf("Function copy_str:\n");
			printf("%c\n", src[i]);
			i++;
		}
		dest[i] = '\0';
		printf("END\n");
	}
	return (src);
}


int count_till_nl(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
		//printf("%d", i);
        i++;
		
    }
    if (str[i] == '\0')
	{
        return (i);
	}
	return(++i);// why not i++ ?
}
int count_after_nl(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i] != '\n' && str[i] != '\0')
    {
        i++;
    }
	if (str[i] == '\n')
	{	
		i++;
		while(str[i] != '\0')
    	{
			i++;
        	count++; 
    	}
	}
    return (count); 
}

int check_nl_escape(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *copy_first_line(char * str)
{
	int count;
	char *line;

	count = count_till_nl(str);
	line = malloc(sizeof(char) *(ft_strlen(str) + 1));
	if (!line)
		return (NULL);
	//printf("%s\n",line);
	copy_str(line, str, count); // why i cannot do line = copy_str(line, str, count);
	printf("%s\n",line);
	return (line);
}
char *read_till_nl(int fd, char *str) // const char?
{
    char *buffer;
    int i;
    int fd_read;
    
    i = 0;
    fd_read = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while(!check_nl_escape(str) && fd_read > 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		buffer[fd_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
    return (str);
}

char *update_statik_str(char *old_str)
{
	char *new_str;
	int size;
	int start;

	size = count_after_nl(old_str);
	start = count_till_nl(old_str);
	if (size == 0)
	{
		free(old_str);
		return(NULL);
	}
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
	{
		free(old_str);
		return(NULL);
	}
	new_str = copy_str(new_str, old_str + start, size);
	free(old_str);
	return(new_str);
}

int main()
{
    //int fd_open = open("file_to_read.txt", O_RDONLY);
    char *str;
	//char * line;
	char c = 'a';

	str = malloc(1 * (7));
	int i = 0;
	while(i < 7)
	{
		str[i] = c;
		i++;
		c++;
	}
	str[3] = '\n';
	int before = count_till_nl(str);
	int after = count_after_nl(str);
	//printf("%d\n", before);
	//printf("%d\n", after);
	//printf("%s\n",str);
	str = copy_first_line(str);
	printf("%s",str);

    
}*/