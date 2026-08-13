/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:04:08 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 18:16:12 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Eliminamos salto de línea */

char	*ft_remove_newline(char *str)
{
	char	*new_str;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len == 0)
		return (str);
	new_str = malloc(len);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	ft_memcpy(new_str, str, len - 1);
	new_str[len - 1] = '\0';
	free(str);
	return (new_str);
}

/*FT_PROCESS_LINE:
   Lee una línea del archivo y elimina el salto de línea,
   ft_split: Convertimos en tokens todos los elementos de cada línea \n */

int	ft_process_line(char ***tokens, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (FAILURE);
	line = ft_remove_newline(line);
	if (!line)
	{
		printf(RED"Error: Memory allocation failed.\n"RESET);
		return (FAILURE);
	}
	*tokens = ft_split(line, ' ');
	free(line);
	if (!*tokens)
	{
		printf(RED"Error: ft_split failed.\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}
/* ft_checker_textures: Comprobamos que las texturas están cargadas,
   comprobando que las flags = 1*/

void	ft_checker_textures(t_data *cub, char **cell)
{
	if (cell[0] && cell[1] && !ft_strcmp(cell[0], "NO"))
	{
		cub->textures.no_path = ft_strdup(cell[1]);
		cub->textures.no_flag = 1;
	}
	else if (cell[0] && cell[1] && !ft_strcmp(cell[0], "SO"))
	{
		cub->textures.so_path = ft_strdup(cell[1]);
		cub->textures.so_flag = 1;
	}
	else if (cell[0] && cell[1] && !ft_strcmp(cell[0], "EA"))
	{
		cub->textures.ea_path = ft_strdup(cell[1]);
		cub->textures.ea_flag = 1;
	}
	else if (cell[0] && cell[1] && !ft_strcmp(cell[0], "WE"))
	{
		cub->textures.we_path = ft_strdup(cell[1]);
		cub->textures.we_flag = 1;
	}
}
