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

int check_nl_escape(char *str)
{
	int i;

	i = 0;
    if(!str)
        return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
        {
			return (1);
        }
		i++;
	}
	return (0);
}
char *read_till_nl(int fd, char *str) // const char?
{
    char *buffer;
    int i;
    int fd_read;
    int BUFFER_SIZE = 4; // NOT IN THE REAL FUNCT;
    
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
//NOT USING THIS ONE !!!!
/*char	*copy_str(char *dest, char *src, size_t size)
{
	size_t	i;

    if (ft_strlen(dest) < ft_strlen(src))
        return (NULL);
	i = 0;
	if (size > 0)
	{
		while ((i < size - 1) && (src[i]))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src);
}*/

char *copy_first_line(char * str)
{
	int count;
	char *line;

	count = count_till_nl(str);
	line = malloc(sizeof(char) *(count + 1)); 
	if (!line)
		return (NULL);
	//printf("%s\n",line);
	ft_memcpy(line, str, count); // why i cannot do --- line = copy_str(line, str, count) --- ?
	return (line);
}


int main(void)
{
    // printf("%c",funt());
    //int count2 = count();
    //checking --- int check_nl_escape(char *str) ---
    /*char *str;
    int i = 0;
    str = malloc(6);

    while(i < 5)
    {
        str[i] = i + 66;
        i++;
    }

    str[4] = '\n';// we can add '\n', or not
    str[5] = '\0';
    printf("%s\n", str);
    int res_escape = check_nl_escape(str);
    printf("Result of check_nl_escape: ");
    printf("%d\n", res_escape);*/

    //checking --- read_till_nl(int fd, char *str) ---
    /*int fd_open = open("file_to_read.txt", O_RDONLY);
    static char *statik;
    //statik = malloc(6);
    //statik = "123\n45122222\n2222222";
    statik = read_till_nl(fd_open, statik);
    printf("Result of read_till_nl: ");
    printf("%s\n", statik);*/

    //checking --- int count_till_nl(char *str) ---
    /*char str_1[13] = "12345\n678"; //output : 6
    char str_2[13] = "12345"; // //output : 5

    printf("%d\n", count_till_nl(str_1));
    printf("%d\n", count_till_nl(str_2));*/

    //checking -- char	*copy_str(char *dest, char *src, size_t size) --
    /*char dest[11] = "12345678901";
    char src[12] = "123456789012";
    int count_till = count_till_nl(src);
    //copy_str(dest, src, count_till);
    printf("%s", copy_str(dest, src, count_till));*/

    //checking -- char *copy_first_line(char * str) --
    /*static char *statik_1;
    statik_1 = malloc(6);
    int i = 0;
    while(i < 5)
    {
        statik_1[i] = i + 100;
        printf("%c", statik_1[i]);
        i++;
    }
    printf("\n");
    //statik_1[2] = '\n';
    statik_1[4] = '\n';

    char *line;

    line = copy_first_line(statik_1);
    printf("%s", line);*/



    //char		*line;
    //line = copy_first_line(statik);
    //printf("Result of copy_first_line: ");
    //printf("%s\n", line);

	//printf("%s", get_next_line(fd_open));

    return (0);
}