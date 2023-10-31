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
	printf("ft_strlen done\n");
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
	{
		printf("ft_strjoin NULL\n");
		return (NULL);
	}
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
	printf("ft_strjoin done\n");
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
			printf("check_nl_escape done\n");
			return (1);
        }
		i++;
	}
	printf("check_nl_escape done\n");
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
	{
		printf("read_till_nl NULL\n");
		return (NULL);
	}
	while(!check_nl_escape(str) && fd_read > 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		buffer[fd_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	printf("%s\n", str);
	printf("read_till_nl done\n");
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
		printf("count_till_nl done\n");
        return (i);
	}
	printf("count_till_nl done\n");
	return(++i);// why not i++ ?
}

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;
	free(dest);
	dest = malloc(sizeof(char) *(ft_strlen(src) +1));

	i = 0;
	if (dest == src)
	{
		printf("ft_strncpy done\n");
		return (dest);
	}
	while (i < n)
	{
		(dest)[i] = (src)[i];
		i++;
	}
	dest[i] = '\0';
	printf("ft_strncpy done\n");
	return (dest);
}


char *copy_first_line(char * str)
{
	int count;
	char *line;

	count = count_till_nl(str);
	line = malloc(sizeof(char) *(count + 1)); 
	if (!line)
	{
		printf("copy_first_line NULL\n");
		return (NULL);
	}
	line[count] = '\0';
	//printf("%s\n",line);
	ft_strncpy(line, str, count); // why i cannot do --- line = copy_str(line, str, count) --- ?
	printf("copy_first_line done\n");
	return (line);
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
		//count++;
    }
	if (str[i] == '\n')
	{	
		//count = 0;
		i++;
		while(str[i] != '\0')
    	{
			i++;
        	count++; 
    	}
	}
	printf("count_after_nl done\n");
    return (count); 
}

char *update_statik_str(char *old_str)
{
	char *new_str;
	int size;
	int start;

	size = count_after_nl(old_str);
	start = count_till_nl(old_str);
	
	new_str = malloc(sizeof(char) * (size + 1));
	if (size == 0 || !new_str)
	{
		free(old_str);
		printf("update_statik_str NULL\n");
		return(NULL);
	}
	
	/*if ()
	{
		free(old_str);
		return(NULL);
	}*/
	new_str = ft_strncpy(new_str, old_str + start, size);
	free(old_str);
	printf("update_statik_str done\n");
	return(new_str);
}
char *get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	
	statik = read_till_nl(fd, statik);
	line = copy_first_line(statik);
	statik = update_statik_str(statik);

	printf("update_statik_str done\n");
	return (line);

}


int main(void)
{
   //checking --- char *get_next_line(int fd)) ---
   	int fd_open = open("file_to_read.txt", O_RDONLY);
	printf("%s", get_next_line(fd_open));

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


	// checking -- int count_after_nl(char *str) --
	/*static char * statik_2;
	statik_2 = malloc(7);
	statik_2[0] = 'a'; statik_2[1] = 'a'; statik_2[2] = 'a';
	statik_2[3] = ' '; statik_2[4] = '\n'; statik_2[5] = ' '; statik_2[6] = '\0';
	int res_count_after = count_after_nl(statik_2);
	printf("%d", res_count_after);*/
	


	// checking -- char *update_statik_str(char *old_str) --
	/*char *statik_3 = malloc(6);
	char *to_be_updated;
	int size;
	int start;
	char *new_str;

	int i = 0;
	while(i < 5)
    {
        statik_3[i] = i + 49;
        i++;
    }
	statik_3[2] = '0';
    statik_3[5] = '\0';
	printf("statik_3: {%s}\n", statik_3);
	to_be_updated = update_statik_str(statik_3);
	printf("statik_3_updated): {%s}\n", to_be_updated);
	start = count_till_nl(statik_3);
	size = count_after_nl(statik_3);

	//printf("start: %d\n", start);
	//printf("size_t n: %d\n", size);
	new_str = malloc(sizeof(char) * (size + 1));
	if (size == 0 || !new_str)
	{
		free(statik_3);
		return 0;
	}
	

	new_str = ft_strncpy(new_str, statik_3 + start, size);*/

	//printf("statik_3 + start (dest): {%s}\n", statik_3 + start);
	//printf("new_str (src): {%s}\n", new_str);



    //char		*line;
    //line = copy_first_line(statik);
    //printf("Result of copy_first_line: ");
    //printf("%s\n", line);

	//printf("%s", get_next_line(fd_open));

    return (0);
}