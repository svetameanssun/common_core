/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:11:17 by marigome          #+#    #+#             */
/*   Updated: 2025/02/19 16:48:34 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_ray_values(t_data *cub, t_ray *ray)
{
	ray->ray_move_x = 0;
	ray->ray_move_y = 0;
	ray->x_map = cub->player.map_x;
	ray->y_map = cub->player.map_y;
	ray->x_player_pos = cub->player.pos_player_x;
	ray->y_player_pos = cub->player.pos_player_y;
	ray->ray_x = cos(ray->angle);
	ray->ray_y = sin(ray->angle);
	ray->ray_dist_to_x = 1 / fabs(ray->ray_x);
	ray->ray_dist_to_y = 1 / fabs(ray->ray_y);
	if (ray->ray_x < 0)
		ray->ray_move_x = -1;
	else
		ray->ray_move_x = 1;
	if (ray->ray_y < 0)
		ray->ray_move_y = -1;
	else
		ray->ray_move_y = 1;
	ray->flag = 0;
}

/* ft_wall_finder:
 * Va recorriendo cada celda del mapa hasta que encuentra un 1.
*/

void	ft_wall_finder(t_data *cub, t_ray *ray)
{
	while ((cub->map.map[ray->y_map][ray->x_map] != '1'))
	{
		if (ray->cell_crossing_dist_x < ray->cell_crossing_dist_y)
		{
			ray->cell_crossing_dist_x += ray->ray_dist_to_x;
			ray->x_map += ray->ray_move_x;
			ray->flag = 0;
		}
		else
		{
			ray->cell_crossing_dist_y += ray->ray_dist_to_y;
			ray->y_map += ray->ray_move_y;
			ray->flag = 1;
		}
	}
	if (ray->flag == 0)
		ray->wall_ray_hit_dist = (ray->x_map - ray->x_player_pos + \
				(1 - ray->ray_move_x) / 2) / ray->ray_x;
	else
		ray->wall_ray_hit_dist = (ray->y_map - ray->y_player_pos + \
				(1 - ray->ray_move_y) / 2) / ray->ray_y;
}

/* ft_dist_player_to_wall:
 * Calcula la distancia desde posición jugador y la primera intersección
 * de una celda en X (ray->cell_crossing_dist_x)
 * y en Y (ray->cell_crossing_dist_y)
 * Es el primer paso para determinar qué pared tocará primero el rayo
*/

void	ft_dist_player_to_wall(t_data *cub, t_ray *ray)
{
	if (ray->ray_x > 0)
		ray->cell_crossing_dist_x = (cub->player.map_x + \
			ray->ray_move_x - cub->player.pos_player_x) * ray->ray_dist_to_x;
	else
		ray->cell_crossing_dist_x = (cub->player.pos_player_x - \
			cub->player.map_x) * ray->ray_dist_to_x;
	if (ray->ray_y > 0)
		ray->cell_crossing_dist_y = (cub->player.map_y + \
			ray->ray_move_y - cub->player.pos_player_y) * ray->ray_dist_to_y;
	else
		ray->cell_crossing_dist_y = (cub->player.pos_player_y - \
			cub->player.map_y) * ray->ray_dist_to_y;
}

/* ft_ray_impact: Inicia el proceso de detección de impacto con las paredes.
 * - Objetivo: calcular la distancia hasta la primera pared
 *   y determinar el punto de impacto.*/

void	ft_ray_impact(t_data *data, t_ray *ray)
{
	ft_init_ray_values(data, ray);
	ft_dist_player_to_wall(data, ray);
	ft_wall_finder(data, ray);
	if (ray->flag == 0)
		ray->texture_coord = ray->y_player_pos \
				+ (ray->wall_ray_hit_dist * ray->ray_y);
	else
		ray->texture_coord = ray->x_player_pos \
				+ (ray->wall_ray_hit_dist * ray->ray_x);
	ft_size_wall_on_window(ray);
	ft_hypo(ray);
	ft_vert(data, ray);
}

void	ft_raycasting(t_data *data, t_player *player)
{
	int	i;

	i = 0;
	ft_ray_init(data);
	while (i < WIDTH)
	{
		ft_ray_impact(data, &player->ray[i]);
		ft_painting_col(data, &player->ray[i], i);
		i++;
	}
}
