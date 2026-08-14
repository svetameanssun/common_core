/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_painting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:24:30 by marigome          #+#    #+#             */
/*   Updated: 2025/02/19 16:53:43 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_wall_size: Calculamos la altura de la pared en pantalla 
	Devuelve el tamaño en píxeles en pantalla */
static double	ft_wallsize(t_ray *ray)
{
	return (HEIGHT / ray->wall_ray_hit_dist);
}

/* ft_rgba: Convierte valores RGBA en un solo número (uint32_t)*/
static uint32_t	ft_rgba(uint8_t pixel[4])
{
	uint32_t	p;

	p = 0;
	p |= ((uint32_t)pixel[0] << 24);
	p |= ((uint32_t)pixel[1] << 16);
	p |= ((uint32_t)pixel[2] << 8);
	p |= pixel[3];
	return (p);
}

/* ft_get_colors: Obtiene el color correcto de la textura en función
	de la posición de impacto del rayo.
	- x: Coordenada horizontal de impacto (valor entre 0 y 1)
	- y Coordenada vertical de impacto (valor entre 0 y 1)
	- *texture: Textura a utilizar
	
	- texture_index: Extrae los valores RGBA en esa posición (x, y)*/

static uint32_t	ft_get_colors(double x, double y, mlx_texture_t *texture)
{
	uint8_t			rgba[4];
	uint32_t		texture_index;
	unsigned int	i;

	i = 0;
	if (!texture || !texture->pixels || x >= 1 || y >= 1)
		return (0);
	texture_index = ((uint32_t)(texture->height * y) * texture->width \
			+ (uint32_t)(texture->width * x)) * texture->bytes_per_pixel;
	while (i < 4)
	{
		rgba[i] = texture->pixels[texture_index + i];
		i++;
	}
	return (ft_rgba(rgba));
}

/* ft_walls_colors: Determina qué textura usar según la dirección del rayo
	Variables: cub, ray, y (Coordenada vertical del impacto) 
	*/
static uint32_t	ft_walls_colors(t_data *cub, t_ray *ray, double y)
{
	uint32_t	c;

	if (ray->flag == 0)
	{
		if (ray->ray_x > 0)
			c = ft_get_colors(ray->texture_coord - (int)ray->texture_coord, \
				y, cub->textures.ea_texture);
		if (ray->ray_x < 0)
			c = ft_get_colors(ray->texture_coord - (int)ray->texture_coord, \
				y, cub->textures.we_texture);
		return (c);
	}
	else if (ray->flag == 1)
	{
		if (ray->ray_y > 0)
			c = ft_get_colors(ray->texture_coord - (int)ray->texture_coord, \
			y, cub->textures.so_texture);
		if (ray->ray_y < 0)
			c = ft_get_colors(ray->texture_coord - (int)ray->texture_coord, \
				y, cub->textures.no_texture);
		return (c);
	}
	return (0x33333388);
}

/* ft_painting_col: Dibuja la columna de píxeles de la pared en la pantalla */

void	ft_painting_col(t_data *data, t_ray *ray, int col)
{
	double		size;
	uint32_t	color;
	int			i;
	int			first_pixel;
	int			pixels;

	i = 0;
	pixels = 0;
	size = ft_wallsize(ray);
	first_pixel = ((HEIGHT / 2) - (size / 2));
	if (first_pixel < 0)
	{
		pixels = -first_pixel;
		first_pixel = 0;
	}
	while (i < HEIGHT)
	{
		if (i > first_pixel && i < HEIGHT - 1)
		{
			color = ft_walls_colors(data, ray, \
				(i - first_pixel + pixels) / size);
			mlx_put_pixel(data->walls, col, i, color);
		}
		i++;
	}
}
