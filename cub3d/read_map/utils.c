/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:15:44 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 18:09:03 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_split_len(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char	*copy_realloc(char *new_ptr, char *ptr, int size)
{
	int	ptr_len;

	ptr_len = ft_strlen(ptr);
	if (ptr_len > size - 1)
		ptr_len = size - 1;
	ft_memcpy(new_ptr, ptr, ptr_len);
	new_ptr[ptr_len] = '\0';
	free(ptr);
	return (new_ptr);
}

char	*ft_realloc(char *ptr, int size)
{
	char	*new_ptr;

	new_ptr = NULL;
	if (size <= 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
	{
		new_ptr = malloc(sizeof(char) * size);
		return (new_ptr);
	}
	new_ptr = malloc(sizeof(char) * size + 1);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = copy_realloc(new_ptr, ptr, size);
	return (new_ptr);
}

char	*ft_new_strjoin(char *s1, char *s2)
{
	size_t		totallen;
	char		*buffer;
	int			len_s1;
	int			len_s2;

	if (!s2)
		return (s1);
	if (!s1)
		return (ft_strdup(s2));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	totallen = len_s1 + len_s2;
	buffer = (char *)malloc(sizeof(char) * (totallen + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, len_s1);
	ft_memcpy(buffer + len_s1, s2, len_s2);
	buffer[totallen] = '\0';
	free (s1);
	return (buffer);
}

int	ft_checker_extension(char *file)
{
	char	*extension;

	if (!file)
		return (FAILURE);
	extension = ft_strrchr(file, '.');
	if (!extension || ft_strcmp(extension, ".cub") != 0)
	{
		printf(RED"Error\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
