/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:20:17 by marigome          #+#    #+#             */
/*   Updated: 2025/02/26 18:54:07 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_load_png: En esta función cargamos las rutas de las texturas
 * a elemento mlx utilizando
    librería propia*/

void	ft_load_png(t_data *data)
{
	data->textures.no_texture = mlx_load_png(data->textures.no_path);
	if (!data->textures.no_texture)
		exit(1);
	data->textures.so_texture = mlx_load_png(data->textures.so_path);
	if (!data->textures.so_texture)
		exit(1);
	data->textures.we_texture = mlx_load_png(data->textures.we_path);
	if (!data->textures.we_texture)
		exit(1);
	data->textures.ea_texture = mlx_load_png(data->textures.ea_path);
	if (!data->textures.ea_texture)
		exit(1);
}

/* ft_create_image: Creamos espacios en memoria
 * para las imágenes que vamos a utilizar */

void	ft_create_image(t_data *data, mlx_image_t **image)
{
	*image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!*image)
	{
		printf(RED "Error al inicializar la imagen\n" RESET);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, *image, 0, 0) == -1)
	{
		printf(RED "Error al renderizar la imagen\n" RESET);
		exit(EXIT_FAILURE);
	}
}

/* ft_init_mlx: Inicializamos mlx y guardamos espacio de memoria
 * para las imágenes que
    vamos a utilizar (ft_init_walls) */

void	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	if (!data->mlx)
	{
		printf(RED"Error al inicializar la ventana\n"RESET);
		return ;
	}
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	ft_create_image(data, &data->image);
	ft_create_image(data, &data->walls);
	data->move = 4;
}

/* ft_print_walls_and_floor: Las paredes empiezan a pintarse
 * desde arriba (0) hacia abajo 
	por ese motivo si estamos en la mitad superior pintamos cielo
	y mitad inferior cargamos suelo */

void	ft_print_walls_and_floor(t_data *data)
{
	int	width;
	int	height;

	width = 0;
	while (width < WIDTH)
	{
		height = 0;
		while (height < HEIGHT)
		{
			if (height < HEIGHT / 2)
				mlx_put_pixel(data->image, width, \
				height++, data->textures.ceiling_color);
			else
				mlx_put_pixel(data->image, width, \
				height++, data->textures.floor_color);
		}
		width++;
	}
}

/* ft_init_play: Función que integra todos los elementos necesarios
 * para que el juego se active:
    - ft_init_mlx -> Inicializamos mlx (Cargamos imágenes,
		inicializamos paredes y suelos)
    - Pintamos paredes y suelos (ft_print_walls_and_floor) 
    - ft_mlx_loop_hook -> Incluimos función que se ejecuta
	en cada iteración (while 1)*/

void	ft_init_play(t_data *data)
{
	ft_init_mlx(data);
	ft_player_position(data, data->map.map);
	ft_print_walls_and_floor(data);
	mlx_loop_hook(data->mlx, ft_game_loop, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
