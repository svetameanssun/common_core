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
}*/

int count_till_nl(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n'|| str[i] != '\0')
    {
        i++;
    }
    if (str[i] == '\0')
        return (i);
    return(i++);
}

/*char *read_till_nl(int fd, char *str) // const char?
{
    char *buffer;
    int i;
    int fd_read;
    
    i = 0;
    fd_read = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));




    return (str);
}*/

int main()
{
    /*int fd_open = open("file_to_read.txt", O_RDONLY);
    char * str;
    //str = read_till_nl(fd_open, str);
    printf("%s", read_till_nl(fd_open, str));*/
    char str[10] = "abc\ndddd";
    printf("%d", count_till_nl(str));
    return 0;
}