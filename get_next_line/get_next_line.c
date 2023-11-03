/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:17 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/03 16:36:19 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char *read_all(int fd, char *str) // const char?
{
    char *buffer;
    int i;
    int fd_read;
    //int BUFFER_SIZE = 1; // NOT IN THE REAL FUNCT;
    
    i = 0;
    fd_read = 1;
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	while(!check_nl_escape(str)&& fd_read != 0)
		{
			fd_read = read(fd, buffer, BUFFER_SIZE);
			if(fd_read == -1)
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


char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	i = 0;
	if (dest == 0)
	{
		return (src);
	}
	while (i < n)
	{
		(dest)[i] = (src)[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


char *copy_first_line(char * str)
{
	int count;
	char* line;
	int i;

	count = count_till_nl(str);
	if(count == 0)
		return (NULL);
	//line = ft_strncpy(line, str, count); // why i cannot do --- line = copy_str(line, str, count) --- ?

	line = malloc(sizeof(char) * (count + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < count)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}



char *update_statik_str(char *old_str)
{
	char *new_str;
	int size;
	int start;


	size = 0;
	new_str = 0;
	while(old_str[size] && old_str[size] != '\n')
		size++;
	start = count_till_nl(old_str);
	if (old_str[size] == '\0')
	{
		printf("YYYYYYYYYY\n");
		free(old_str);
		return (NULL);
	}
	if (!old_str)
	{
		free(old_str);
		return(NULL);
	}
	new_str = ft_strncpy(new_str, old_str + start, size);
	free(old_str);
	return(new_str);
}
char *get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	if (fd < 0)
		return (NULL);
	
	statik = read_all(fd, statik);// null;
	if (!statik)
		return (NULL);
	line = copy_first_line(statik);
	statik = update_statik_str(statik);
	return (line);
}

/*int main(void)
{
   //checking --- char *get_next_line(int fd)) ---
   	int fd_open = open("file_to_read.txt", O_RDONLY);
	//get_next_line(fd_open);
	printf("%s", get_next_line(fd_open));
	close(fd_open);
	   return (0);
}*/