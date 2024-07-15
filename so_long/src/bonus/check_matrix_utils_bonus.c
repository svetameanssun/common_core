/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:23:33 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 19:54:17 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_elem(int c, int elem)
{
	if (c == elem)
		return (1);
	return (0);
}

size_t	ft_strlen_sl(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

int	count_map_lines(char *map_name)
{
	int		count;
	char	*str;
	int		fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		manage_prog_error(NULL, ERROR_FD);
	str = get_next_line(fd);
	free(str);
	count = 0;
	while (str)
	{
		str = get_next_line(fd);
		free(str);
		count++;
	}
	close(fd);
	return (count);
}

int	check_map_name(char *map_name)
{
	int	len;
	int	res;
	int	i;

	i = 0;
	len = ft_strlen(map_name);
	if (len <= 4)
		return (ERROR_MAP_NAME);
	while (map_name[i] != '.')
	{
		i++;
	}
	if (i == 0)
		return (ERROR_MAP_NAME);
	if (map_name[i - 1] == '/')
		return (ERROR_MAP_NAME);
	res = ft_strncmp(map_name + i, ".ber", 4);
	if (res != 0)
		return (ERROR_MAP_NAME);
	return (0);
}
