/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:00:55 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 18:01:46 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	*ft_split_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	free_textures(t_texture *textures)
{
	if (textures->no_path)
		free(textures->no_path);
	if (textures->so_path)
		free(textures->so_path);
	if (textures->we_path)
		free(textures->we_path);
	if (textures->ea_path)
		free(textures->ea_path);
}

void	free_mlx_textures(t_texture *textures)
{
	if (textures->no_texture)
		mlx_delete_texture(textures->no_texture);
	if (textures->so_texture)
		mlx_delete_texture(textures->so_texture);
	if (textures->we_texture)
		mlx_delete_texture(textures->we_texture);
	if (textures->ea_texture)
		mlx_delete_texture(textures->ea_texture);
}

void	*free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}
