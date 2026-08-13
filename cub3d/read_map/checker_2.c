/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:35:55 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 16:57:36 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*ft_check_text: Esta función se encarga de analizar que:
   ft_check_imgs: Las texturas tienen el formato correcto.
   ft_store_texture: Inicializamos y cargamos las texturas en la estructura
*/

int	ft_check_text(t_data *info, char **c, int *i, int line)
{
	if (!c[0])
	{
		ft_split_free(c);
		return (SUCCESS);
	}
	if (ft_check_imgs(c, line, info))
		return (FAILURE);
	ft_checker_textures(info, c);
	ft_store_color(info, c);
	ft_split_free(c);
	(*i)++;
	return (SUCCESS);
}

/* Comprobamos que los tokens están separados por , */

int	ft_check_comma(char **c)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (c[i][j] == ',')
				n++;
			j++;
		}
		i++;
	}
	return (n);
}

int	ft_check_imgs(char **c, int i, t_data *info)
{
	if (ft_check_cardinal(c, i, info)
		|| ft_check_path(c)
		|| ft_check_bad_argument(c, i)
		|| ft_check_file(c[0], c[1], i)
		|| ft_check_colors(c, i)
		|| ft_check_colors_num(c))
		exit(EXIT_FAILURE);
	return (SUCCESS);
}

int	ft_check_colors_num(char **c)
{
	int	flag;
	int	i;
	int	j;

	i = 1;
	flag = 0;
	if (ft_strcmp(c[0], "F") && ft_strcmp(c[0], "C"))
		return (SUCCESS);
	while (c[i])
	{
		j = 0;
		while (c[i][j])
		{
			if (!ft_isdigit(c[i][j]) && c[i][j] != ',')
			{
				ft_error_color(c);
				flag = 1;
			}
			j++;
		}
		i++;
	}
	if (flag == 1)
		return (FAILURE);
	return (SUCCESS);
}

void	fill_ids_and_flags(const char *identifiers[4],
	int *flags[4], t_data *info)
{
	identifiers[0] = "NO";
	identifiers[1] = "SO";
	identifiers[2] = "WE";
	identifiers[3] = "EA";
	flags[0] = &info->textures.no_flag;
	flags[1] = &info->textures.so_flag;
	flags[2] = &info->textures.we_flag;
	flags[3] = &info->textures.ea_flag;
}
