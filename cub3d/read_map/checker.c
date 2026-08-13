/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:10:37 by marigome          #+#    #+#             */
/*   Updated: 2025/02/19 16:59:50 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_colors(char **c, int i)
{
	int	len;

	(void)i;
	len = ft_split_len(c);
	if (ft_strcmp(c[0], "C") && ft_strcmp(c[0], "F"))
		return (SUCCESS);
	if (len != 2 && len != 4)
	{
		printf(RED"Error\n"RESET);
		exit(EXIT_FAILURE);
	}
	if (ft_check_comma(c) != 2)
	{
		printf(RED"Error\n"RESET);
		exit(EXIT_FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_file(char *file, char *img, int i)
{
	int	fd;

	(void)i;
	if (!ft_strcmp(file, "C") || !ft_strcmp(file, "F"))
		return (SUCCESS);
	fd = open(img, O_RDONLY);
	if (fd < 0)
	{
		printf(RED"Error\n"RESET);
		return (FAILURE);
	}
	close(fd);
	return (SUCCESS);
}

int	ft_check_bad_argument(char **c, int i)
{
	(void)i;
	if (c && c[2] && ft_strcmp(c[0], "C")
		&& ft_strcmp(c[0], "F") && c[0][0] != '1')
		return (FAILURE);
	return (SUCCESS);
}

int	ft_check_path(char **c)
{
	if (!c[1])
	{
		printf(RED"Error\n"RESET);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_cardinal(char **c, int i, t_data *info)
{
	const char	*identifiers[4];
	int			*flags[4];
	int			j;

	j = 0;
	fill_ids_and_flags(identifiers, flags, info);
	(void)i;
	while (j < 4)
	{
		if (ft_strcmp(c[0], identifiers[j]) == 0)
		{
			if (*flags[j] == 1)
			{
				printf(RED"Error\n"RESET);
				return (FAILURE);
			}
			*flags[j] = 1;
			return (SUCCESS);
		}
		j++;
	}
	return (SUCCESS);
}
