/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:31:50 by marigome          #+#    #+#             */
/*   Updated: 2025/02/17 17:12:16 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* ft_valid_movement: Comprueba que las esquinas de las celdas no sean 1.
	- Verificamos la posición del jugador en píxeles ( / 32 )*/

int	ft_valid_movement(t_data *cub, double move_x, double move_y)
{
	int	verify_x;
	int	verify_x2;
	int	verify_y;
	int	verify_y2;

	verify_x = (int)floor((cub->player.pos_player_x + 0.25) + (move_x / 32));
	verify_x2 = (int)floor((cub->player.pos_player_x - 0.25) + (move_x / 32));
	verify_y = (int)floor((cub->player.pos_player_y + 0.25) + (move_y / 32));
	verify_y2 = (int)floor((cub->player.pos_player_y - 0.25) + (move_y / 32));
	if (cub->map.map[verify_y][verify_x] == '1')
		return (0);
	if (cub->map.map[verify_y2][verify_x] == '1')
		return (0);
	if (cub->map.map[verify_y][verify_x2] == '1')
		return (0);
	if (cub->map.map[verify_y2][verify_x2] == '1')
		return (0);
	return (1);
}

/* ft_lets_move: No permite el movimiento si chocamos con una pared.
	- Actualizamos la posición del jugador en el mapa */

int	ft_lets_move(t_data *cub, double move_x, double move_y)
{
	if (!ft_valid_movement(cub, move_x, move_y))
		return (0);
	cub->player.map_x = cub->player.pos_player_x + move_x / 32;
	cub->player.map_y = cub->player.pos_player_y + move_y / 32;
	return (1);
}

/* ft_movement: Convertimos los ángulos en radianes (cos y sen)
	- ft_lest_move: Actualizamos la posición del jugador en el mapa
	(map_x e map_y)
	- Si es un movimiento válido: movemos al jugador */

void	ft_movement(t_data *cub, double angle)
{
	double	move_x;
	double	move_y;

	move_x = (cos(angle * M_PI / 180) * cub->move);
	move_y = (sin(angle * M_PI / 180) * cub->move);
	if (ft_lets_move(cub, 0, move_y))
		cub->player.pos_player_y += move_y / 32;
	if (ft_lets_move(cub, move_x, 0))
		cub->player.pos_player_x += move_x / 32;
}
/* ft_rotate_player: Movemos el ángulo del jugador.
	- Si el jugador mira al note (270º) y presionamos derecha,
	el ángulo sube: 270 + 3
	- Si seguimos presionando llegará un momento que sea == 360º
	lo que significa que está en el mismo
	 punto de partida */

void	ft_rotate_player(double *angle, double i)
{
	*angle += i;
	if (*angle >= 360)
		*angle -= 360;
	if (*angle < 0)
		*angle += 360;
}
/* ft_update_moves: Detecta la tecla que presionamos y mueve al jugador */

void	ft_update_moves(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_movement(data, data->player.angle);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_movement(data, data->player.angle + 180);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_movement(data, data->player.angle - 90);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_movement(data, data->player.angle + 90);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_rotate_player(&data->player.angle, -3);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_rotate_player(&data->player.angle, +3);
}
