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
	return(i++);// or ++i ?
}*/
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

/*int check_nl_escape(char *str)
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
}*/

char *update_statik_str(char *old_str)
{
	char *new_str;
	int size;
	int i;

	int size = count_after_nl(old_str);
	if (size == 0);
	{
		free(old_str);
		return(NULL);
	}
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return(NULL);
	

}

int main()
{
    //int fd_open = open("file_to_read.txt", O_RDONLY);
    char str[10] = "abc\n123";
	int res = count_after_nl(str);
    //str = read_till_nl(fd_open, str);
    printf("%d", res);
}