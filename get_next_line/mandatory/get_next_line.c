/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:16:30 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/10 12:47:06 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *read_till_nl(int fd, char * str)
{
	char *buffer;
	int fd_read = 1;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	
	}
	while(!has_nl(str) && fd_read != 0)
	{
		fd_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[fd_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char *ft_strncpy(char *dest, char *src, int n)
{
	int i;
	
	i = 0;
	while(src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *copy_till_nl(char *str)
{
	int len;
	char *new_str;
	int i;
	
	len = count_till_nl(str);
	if (len == 0)
		return (NULL); //important
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while(i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char *update_statik_str(char * old_str)
{
	int size_with_nl;
	int size_after_nl;
	char *new;

	size_with_nl = count_till_nl(old_str);
	size_after_nl = count_after_nl(old_str);

	if (!old_str)
		return(NULL);
	
	new = malloc(sizeof(char) * (size_after_nl + 1));
	if (!new)
		return(NULL);
	new = ft_strncpy(new, old_str + size_with_nl, size_after_nl);
	free (old_str);
	return (new);
}

char *get_next_line(int fd)
{
	static char *statik;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	statik  = read_till_nl(fd, statik);
	if (!statik)
		return(NULL);
	line = copy_till_nl(statik);
	statik = update_statik_str(statik);
	return(line);
}
