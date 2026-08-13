/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:08:43 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 16:57:27 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
   Los radianes son una medida angular que se utiliza en matemáticas
   y en informática
   En este caso, utilizamos la constante M_PI para convertir
   los grados a radianes: 360º = 2 * M_PI
   
   ft_ray_init: En esta función inicializamos los rayos que se van a lanzar
   en el INICIO de la pantalla.
	- El ángulo de visión del jugador es de 60° (FOV)
	- El ángulo inicial se basa en la dirección hacia la que mire el jugador
	- En base a estas 2 variables, completamos el ángulo de visión
	del jugador con rayos según el ancho de la pantalla
	 y lo guardamos en el elemento de la estructura player.ray[WIDTH]

	- fmod: Es una función de maths que devuelve el resto de la división
	de dos números DECIMALES:
		* Double x: base_angle - (vision_player / 2) + angle_rays + (2 * M_PI)
			-> Convertimos el ángulo a radianes y le sumamos 2 * PI
			Para normalizar el ángulo y que no se salga del rango de 0 a 2 * PI
		* Double y: 2 * PI -> Normalizamos el ángulo a 0 y 2 * PI
		double x / double y -> Devuelve el resto de la división de x entre y
*/

void	ft_ray_init(t_data *cub)
{
	int		i;
	double	base_angle;
	double	vision_player;
	double	angle_rays;

	vision_player = (FOV * M_PI) / 180;
	base_angle = (cub->player.angle * M_PI) / 180;
	i = 0;
	while (i < WIDTH)
	{
		angle_rays = (vision_player / WIDTH) * i;
		cub->player.ray[i].angle = fmod(base_angle - (vision_player / 2) \
				+ angle_rays + (2 * M_PI), 2 * M_PI);
		cub->player.ray[i].angle_ret = cub->player.ray[i].angle;
		i++;
	}
}

/* ft_player_angle: Esta función ajusta el ángulo de visión del jugador
	según su posición inicial:
	Utilizamos el sistema de coordenadas de gráficos de pantalla
	(El eje Y aumenta hacia abajo)
	
	- Si el jugador está mirando al Norte, el ángulo es 270°
	(Lo que significa que los rayos van hacia arriba)
	- Si el jugador está mirando al Este, el ángulo es 0°
	(Los rayos giran hacia la derecha)
	- Si el jugador está mirando al Sur, el ángulo es 90°
	(Los rayos giran hacia abajo)
	- Si el jugador está mirando al Oeste, el ángulo es 180° 
	Los rayos giran hacia la izquierda)
*/

static void	ft_player_angle(t_data *data, char position)
{
	char	*directions;
	char	*found;

	directions = "NESW";
	found = ft_strchr(directions, position);
	if (!found)
		return ;
	if (found - directions == 0)
		data->player.angle = 270;
	else if (found - directions == 1)
		data->player.angle = 0;
	else if (found - directions == 2)
		data->player.angle = 90;
	else if (found - directions == 3)
		data->player.angle = 180;
}

/*  ft_player_position: En esta función localizamos al jugador
	en la posición inicial:
	- Le sumamos 0.5 para colocarlo en el centro de la celda
	y que raycasting no de problemas 
	- Recorremos las filas del mapa (int x) y las columnas (int y) 
	
	ft_player_angle: Definimos el ángulo del jugador y hacia donde
	se van a dirigir los rayos */
//added columns++ in the while
static char	ft_find_player_position(t_data *data, char **map)
{
	int		rows;
	int		columns;
	char	position;

	position = '\0';
	rows = 0;
	while (map[rows])
	{
		columns = -1;
		while (map[rows][++columns])
		{
			if (map[rows][columns] == 'N' || map[rows][columns] == 'S'
				|| map[rows][columns] == 'E' || map[rows][columns] == 'W')
			{
				data->player.pos_player_x = columns + 0.5;
				data->player.pos_player_y = rows + 0.5;
				data->player.map_x = columns;
				data->player.map_y = rows;
				position = map[rows][columns];
				return (position);
			}
		}
		rows++;
	}
	return (position);
}

void	ft_player_position(t_data *data, char **map)
{
	char	position;

	position = ft_find_player_position(data, map);
	ft_player_angle(data, position);
}
