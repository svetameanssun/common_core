/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:59:46 by marigome          #+#    #+#             */
/*   Updated: 2025/02/26 18:52:01 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_call_loop -> bucle principal del juego:
	- Eliminamos las imágenes de las paredes antes de redibujar la nueva */

void	ft_game_loop(void *info)
{
	t_data	*data;

	data = info;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	ft_update_moves(data);
	if (data->walls)
		mlx_delete_image(data->mlx, data->walls);
	ft_create_image(data, &data->walls);
	ft_raycasting(data, &data->player);
}
