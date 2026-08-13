/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_borders.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:33:05 by marigome          #+#    #+#             */
/*   Updated: 2025/02/27 14:03:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Comprobamos el borde del mapa */

int	ft_check_border_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
		{
			printf(RED"Error.\n"RESET);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}
/* ft_check_first_last: Comprobamos la primera y la útima línea del mapa */

int	ft_check_first_last(t_data *info, char **map)
{
	if (ft_check_border_line(map[0]))
		return (FAILURE);
	if (ft_check_border_line(map[info->map.map_line - 1]))
		return (FAILURE);
	return (SUCCESS);
}
/* ft_check_border_char: Comprobamos los bordes laterales 
	if is left: Empezamos al inicio de la línea (Lado izquierdo)
	if is left == 0: Revisamos el lado derecho
				(Desde final a principio de la línea)*/

int	ft_check_border_char(char *line, int is_left)
{
	int	i;

	if (is_left == 1)
		i = 0;
	else
		i = ft_strlen(line) - 1;
	while (line[i] == ' ')
	{
		if (is_left == 1)
			i++;
		else
			i--;
	}
	if (line[i] != '1')
		return (FAILURE);
	return (SUCCESS);
}

/* Función en la que revisamos ambos bordes utilizando ft_check_border_char:
	0: lado derecho
	1: lado izquierdo*/

int	ft_check_sides(char **map)
{
	int	i;
	int	error_flag;

	i = 0;
	error_flag = 0;
	while (map[i])
	{
		if (ft_check_border_char(map[i], 1))
			error_flag = 1;
		if (ft_check_border_char(map[i], 0))
			error_flag = 1;
		i++;
	}
	if (error_flag == 1)
		return (FAILURE);
	return (SUCCESS);
}

/* ft_check_map:
	Comprobamos bordes
	Comprobamos inside
	Checkeamos los espacios
	Comprobamos que sólo haya 1 jugador */

int	ft_check_map(t_data *info)
{
	if (!info || !info->map.map)
		return (FAILURE);
	else if (ft_check_first_last(info, info->map.map))
		return (FAILURE);
	else if (ft_check_sides(info->map.map))
		return (FAILURE);
	else if (ft_check_inside(info->map.map))
		return (FAILURE);
	else if (ft_check_spaces(info->map.map))
		return (FAILURE);
	else if (ft_players_num(info->map.map))
		return (FAILURE);
	else if (ft_check_zeros(info->map.map))
		return (FAILURE);
	return (SUCCESS);
}
