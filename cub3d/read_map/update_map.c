/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:34:23 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 18:15:17 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_check_extra: Verifica que no haya líneas vacías entre las
   líneas del mapa */

int	ft_check_extra(char *map)
{
	int	i;

	i = 0;
	if (!map || !map[i] || map[i] == '\n')
	{
		printf(RED"The map is missing.\n"RESET);
		return (FAILURE);
	}
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] != '\0' && map[i] == ' ')
				i++;
			if (map[i] == '\n')
			{
				printf(RED"Empty line in map.\n"RESET);
				return (FAILURE);
			}
		}
		if (map[i] != '\0')
			i++;
	}
	return (SUCCESS);
}

/* ft_split_map: Dividimos el mapa en '\n' */

int	ft_split_map(t_data *info, char *map)
{
	if (!map)
		return (FAILURE);
	if (ft_check_extra(map))
	{
		free(map);
		return (FAILURE);
	}
	info->map.map = ft_split(map, '\n');
	free(map);
	if (!info->map.map)
	{
		printf(RED"Failed in ft_split at ft_split_map function.\n"RESET);
		free(map);
		return (FAILURE);
	}
	info->map.map_line = ft_split_len(info->map.map);
	return (SUCCESS);
}
/* ft_trim_str_inline: Eliminamos carácteres no deseados in situ ('\n')
   Acortamos la línea eliminando (Si tiene) saltos de línea al principio
   y al final de la línea, dejándo únicamente los saltos de línea
   centrales, los cuales luego nos van a servir para utilizar ft_split
   */

void	ft_trim_str_inline(char *s, char *set)
{
	size_t	len;
	size_t	n1;
	size_t	last;

	if (!s || !set)
		return ;
	len = ft_strlen(s);
	n1 = 0;
	while (n1 < len && ft_strchr(set, s[n1]) != NULL)
		n1++;
	last = len;
	while (last > n1 && ft_strchr(set, s[last - 1]) != NULL)
		last--;
	ft_memmove(s, s + n1, last - n1);
	s[last - n1] = '\0';
}

char	*ft_matrix_to_str(char *c, int fd)
{
	char	*map;
	char	*temp;

	map = NULL;
	while (c)
	{
		temp = ft_new_strjoin(map, c);
		if (!temp)
		{
			free(c);
			return (NULL);
		}
		map = temp;
		free(c);
		c = get_next_line(fd);
	}
	return (map);
}

/* ft_get_map:
   Leemos el contenido del mapa:
   - Unimos todo el contenido del mapa
   - Eliminamos el primer y el último salto de línea
   - Volvemos a dividir el mapa según los saltos de línea intermedios
*/

int	ft_get_map(t_data *cub, int fd)
{
	char	*lines;
	char	*map;

	lines = NULL;
	map = NULL;
	lines = get_next_line(fd);
	if (!lines)
		return (EXIT_FAILURE);
	map = ft_matrix_to_str(lines, fd);
	if (!map)
		return (EXIT_FAILURE);
	map = ft_trim_str(map, "\n");
	if (!map)
		return (EXIT_FAILURE);
	if (ft_map_spliting(cub, map))
	{
		free(map);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
