/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:01:51 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 15:54:51 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#include "cub3d.h"

/* ft_update_textures:
 * En esta función comprobamos las 6 primeras variables (N, S, E, O, C y F)
   ft_process_line:
   Leemos cada línea y convertimos en tokens los elementos de cada línea.
   ft_check_text:
   Comprobamos que los argumentos de cada línea sean los correctos:
       i: Contador de texturas, aumenta cada vez que una textura
	   		se procesa correctamente
       j: Contador de líneas leídas en el archivo
   ft_check_map: Comprobamos que el contenido del mapa es correcto
   ft_checker_textures: Comprobamos que las flags de las texturas son = 1
*/

/* ft_store_color: Esta función comprueba (C y F):
   ft_rgb_get: Obtenemos el color en formato RGB
   Comprobamos si c[0] es C o F y almacenamos el color en la estructura */

void	ft_store_color(t_data *info, char **c)
{
	if (!c[0] || !c[1])
		return ;
	if (!ft_strcmp(c[0], "C"))
	{
		info->textures.ceiling_color = ft_rgb_get(c);
		info->textures.color_flag = 1;
	}
	else if (!ft_strcmp(c[0], "F"))
	{
		info->textures.floor_color = ft_rgb_get(c);
		info->textures.floor_flag = 1;
	}
}

int	ft_update_textures(t_data *info, int *res, int *fd)
{
	char	**split_line;
	int		i;
	int		j;

	split_line = NULL;
	i = 0;
	j = 0;
	while (i < 6)
	{
		if (ft_process_line(&split_line, *fd))
			return (FAILURE);
		j++;
		if (ft_check_text(info, split_line, &i, j))
		{
			*res = 1;
			return (FAILURE);
		}
	}
	return (SUCCESS);
}
