/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:50:48 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 17:09:16 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_compute_wall_height: Calcula la altura de la pared 
	Ejemplo:
	- wall_ray_hit_dist = 1.5
	- wall_visible_height = HEIGHT / 1.5 = 480 px.
	(Cuantos más píxeles, más cerca)*/

void	ft_size_wall_on_window(t_ray *ray)
{
	if (ray->wall_ray_hit_dist == 0)
		ray->wall_visible_height = HEIGHT;
	else
		ray->wall_visible_height = HEIGHT / ray->wall_ray_hit_dist;
}

/* ft_hypo: Calculamos la distancia real desde el jugador hasta
	el rayo utilizando el
	TEOREMA DE PITÁGORAS.
	Para obtener distancia usamos la hipotenusa del triángulo formado entre:
	- La posición del jugador (x_player_pos, y_player_pos)
	- El punto de impacto del rayo (wall_ray_hit_dist, x_map/y_map) 
	- pow() -> función de maths que eleva un número a una potencia
		prototipo: pow(double base, double exponente)*/

void	ft_hypo(t_ray *ray)
{
	if (ray->flag == 0 && ray->ray_x > 0)
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->x_map - \
			ray->x_player_pos), 2) + pow((ray->wall_ray_hit_dist - \
				ray->y_player_pos), 2));
	else if (ray->flag == 0 && ray->ray_x < 0)
		ray->ray_hypoteneuse_dist = sqrt(pow(((ray->x_map + 1) - \
			ray->x_player_pos), 2) + pow((ray->wall_ray_hit_dist - \
				ray->y_player_pos), 2));
	else if (ray->flag == 1 && ray->ray_y > 0)
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->wall_ray_hit_dist - \
			ray->x_player_pos), 2) + pow((ray->y_map - ray->y_player_pos), 2));
	else
		ray->ray_hypoteneuse_dist = sqrt(pow((ray->wall_ray_hit_dist - \
			ray->x_player_pos), 2) + pow(((ray->y_map + 1) - \
				ray->y_player_pos), 2));
}

/* ft_vert: Calculamos la distancia corregida para compensar
	la distorsión de perspectiva.
	Explicación: Cuando calculamos la distancia real
	(ray_hypotenuse_dist) no es la misma
	que la que vemos en pantalla. Si usamos ray_hypotenuse_dist,
	las paredes se verían con "efecto ojo de pez".

	Solución: Corregimos la dista ncia del rayo proyectándola
	en un eje vertical usando el COSENO del ángulo entre
	el rayo y la dirección del jugador
*/
void	ft_vert(t_data *cub, t_ray *ray)
{
	double	angle;
	double	player;

	player = cub->player.angle * (M_PI / 180);
	angle = fabs(ray->angle_ret - player);
	if (angle > M_PI)
		angle = 2 * M_PI - angle;
	ray->vertical_ray_travel = ray->ray_hypoteneuse_dist * cos(angle);
	if (ray->vertical_ray_travel < 0.0001)
		ray->vertical_ray_travel = 1;
}
