/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:00:12 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 15:45:17 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_check_adjacent_spaces:
 * Esta función comprueba que no haya espacios alrededor de:
	0 (Suelo) y jugador */

int	ft_check_adjacent_spaces(char **map, int i, int j)
{
	if (i > 0)
	{
		if (map[i - 1][j] == ' ')
			return (1);
	}
	if (map[i + 1])
	{
		if (map[i + 1][j] == ' ')
			return (1);
	}
	return (0);
}
/* ft_is_player_or_zero:
 * El interior del mapa sólo puede ser 0 y (N | S | E | W)*/

int	ft_is_player_or_zero(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

/* ft_check_spaces:
 * Comprobamos que no haya espacios alrededor de 0 y jugadores */

int	ft_check_spaces(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_is_player_or_zero(map[i][j]))
			{
				if (ft_check_adjacent_spaces(map, i, j))
					return (printf(RED"Error\n"RESET), FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
