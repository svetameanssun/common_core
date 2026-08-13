/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:31:11 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 16:31:29 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

/**
 * The get_next_line() function write a function that returns the line read 
 * from a file descriptor.
 * 
 * @param int fd    file descriptor to read from.
 * 
 * returns  If all goes well: the line read
 *          On failure or if reading ends: NULL
 * 
*/

size_t	ft_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnlstrchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_len(str)]);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char		*out;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) == -1)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	str = ft_alloc(fd, str);
	if (!str)
	{
		free(str);
		return (NULL);
	}
	out = ft_nline(str);
	if (!out)
	{
		free(out);
		return (NULL);
	}
	str = ft_rline(str);
	return (out);
}
