/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:41 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/26 14:29:45 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while(str[i] != '\0')
    {
		i++;
        count++; 
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

