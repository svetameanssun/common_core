/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inside.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:58:38 by marigome          #+#    #+#             */
/*   Updated: 2025/02/13 14:15:09 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_players_count: Los jugadores se pueden representar con: (N, S, W, E) */

int	ft_players_count(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

/* ft_players_num: Comprobamos que el número de jugadores sea 1
*/

int	ft_players_num(char **map)
{
	int	count;

	count = ft_players_count(map);
	if (count == 0 || count > 1)
	{
		printf("Error\n");
		return (FAILURE);
	}
	return (SUCCESS);
}
/* ft_valid_char: carácteres válidos dentro del mapa */

int	ft_valid_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == ' ' || c == '1' || c == '0' || c == '\n')
		return (1);
	return (0);
}
/* ft_check_inside: Utilizamos ft_valid_char para recorrer todo el mapa */

int	ft_check_inside(char **map)
{
	int	i;
	int	j;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_valid_char(map[i][j]))
			{
				printf("Error\n");
				error_flag = 1;
			}
			j++;
		}
		i++;
	}
	if (error_flag == 1)
		return (FAILURE);
	return (SUCCESS);
}
