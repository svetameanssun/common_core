/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:19:44 by marigome          #+#    #+#             */
/*   Updated: 2025/02/26 18:28:35 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

unsigned int	ft_rgb_to_hex_split(char **c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;
	char			**rgb;

	rgb = ft_split(c[1], ',');
	if (!rgb)
	{
		printf(RED"Error\n"RESET);
		return (FAILURE);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_split_free(rgb);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		ft_error_color(c);
		return (FAILURE);
	}
	hex = (r << 24 | g << 16 | b << 8 | 0xFF);
	return (hex);
}

unsigned int	ft_rgb_to_hex(char **c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	hex;

	if (!c || !c[0] || !c[1] || !c[2] || !c[3])
		return (FAILURE);
	r = ft_atoi(c[1]);
	g = ft_atoi(c[2]);
	b = ft_atoi(c[3]);
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		ft_error_color(c);
		return (FAILURE);
	}
	hex = (r << 24 | g << 16 | b << 8 | 0xFF);
	return (hex);
}

unsigned int	ft_rgb_get(char **c)
{
	unsigned int	rgb;

	if (ft_split_len(c) == 2)
	{
		rgb = ft_rgb_to_hex_split(c);
		if (rgb == 1)
			rgb = 255;
	}
	if (ft_split_len(c) == 4)
	{
		rgb = ft_rgb_to_hex(c);
		if (rgb == 1)
			rgb = 255;
	}
	return (rgb);
}
