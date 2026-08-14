/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:35:59 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 15:46:49 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_size_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	if (!map->map || !map->map[0])
		return ;
	i = 0;
	j = 0;
	while (map->map[i])
	{
		len = ft_strlen(map->map[i]);
		if (len > j)
			j = len;
		i++;
	}
	map->x_map = j;
	map->y_map = i;
}

int	ft_parse(char *cub, t_data *info)
{
	int	fd;
	int	fault_flag;

	fault_flag = 0;
	info->file = cub;
	fd = open(cub, O_RDONLY);
	if (fd < 0)
	{
		printf(RED"Error\n"RESET);
		return (FAILURE);
	}
	if (ft_update_textures(info, &fault_flag, &fd)
		|| ft_get_map(info, fd) || ft_check_map(info))
		fault_flag = 1;
	close (fd);
	ft_get_size_map(&info->map);
	return (fault_flag);
}
