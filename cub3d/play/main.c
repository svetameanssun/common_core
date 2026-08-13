/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:45:12 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 17:56:20 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* PASOS A SEGUIR:
 * Cargar las texturas (N, S, E, O):
 * mlx_load_png(elemento con path de textura) -> HECHO
 * Cargar elementos de la ventana:
 * mlx_init(width, height, "Name", true (bool resize)) -> HECHO
 * Definir el cursor del ratón (Inactivo)
 * -> mlx_set_cursor_mode(elemento est mlx, DISABLED) -> HECHO
 * Inicialización de elementos:
  * Paredes (mlx_image_t) -> *image =
  * mlx_new_image(elemento a structura mlx, WIDTH, HEIGHT) -> HECHO
             -> mlx_image_to_window(elemento a structura mlx, 0, 0*)  
  * Inicializar el juego (Posicionar al jugador) 
  * remarcar que los movimientos son la posición + 0.5 -> HECHO  */

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2 || ft_checker_extension(argv[1]))
		return (FAILURE);
	ft_init_info_game(&data);
	if (ft_parse(argv[1], &data))
	{
		if (data.map.map)
			free_map(data.map.map);
		free_textures(&data.textures);
		return (EXIT_FAILURE);
	}
	ft_load_png(&data);
	ft_init_play(&data);
	free_map(data.map.map);
	free_textures(&data.textures);
	free_mlx_textures(&data.textures);
	return (0);
}
