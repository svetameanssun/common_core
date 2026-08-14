/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 12:20:57 by marigome          #+#    #+#             */
/*   Updated: 2025/02/27 13:59:34 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_trim_str(char *s1, char *set)
{
	char	*new;

	new = ft_strtrim(s1, set);
	if (s1)
		free(s1);
	return (new);
}

int	ft_checking_lines(char	*map)
{
	int	i;

	if (!map || !map[0])
		return (EXIT_FAILURE);
	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] == ' ')
				i++;
			if (map[i] == '\n' || map[i] == '\0')
				return (EXIT_FAILURE);
		}
		else
			i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_map_spliting(t_data *cub, char *map)
{
	int	flag;

	flag = 0;
	if (ft_checking_lines(map))
		flag = 1;
	if (flag == 1)
		return (EXIT_FAILURE);
	cub->map.map = ft_split(map, '\n');
	free(map);
	if (!cub->map.map)
		return (EXIT_FAILURE);
	cub->map.map_line = ft_split_len(cub->map.map);
	return (EXIT_SUCCESS);
}

int	ft_check_zeros(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map[j][i])
		return (FAILURE);
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] && map[j][i] == '0')
			{
				if (!map[j - 1][i] || !map[j + 1][i])
					return (FAILURE);
				if (!map[j][i - 1] || !map[j][i + 1])
					return (FAILURE);
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (SUCCESS);
}
