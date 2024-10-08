/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:24:51 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 19:26:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	manage_prog_error(t_map *game, int exit_code)
{
	if (exit_code == ERROR_INPUT)
		ft_putstr("Error:\n Invalid number of arguments\n");
	if (exit_code == ERROR_EMPTY_FILE)
		ft_putstr("Error:\n The file is empty.\n");
	if (exit_code == ERROR_MALLOC)
		ft_putstr("Error:\n Memory not allocated using malloc.\n");
	if (exit_code == ERROR_FD)
		ft_putstr("Error:\n Could not open file.\n");
	if (exit_code == ERROR_MLX)
		ft_putstr("Error:\n Could not create MXL.\n");
	if (exit_code == ERROR_SIZE)
		ft_putstr("Error:\n Window is too big.\n");
	if (exit_code == ERROR_LOC)
		ft_putstr("Error:\n Could not load texture.\n");
	free_if_game(game);
	exit(exit_code);
}

void	manage_map_error(t_map *game, int exit_code)
{
	if (exit_code == ERROR_MAP_NAME)
		ft_putstr("Error:\n Wrong map name.\n");
	if (exit_code == ERROR_NO_PATH)
		ft_putstr("Error:\n Invalid path to exit\n");
	if (exit_code == ERROR_NO_RECT)
		ft_putstr("Error:\n Map is not rectangular.\n");
	if (exit_code == ERROR_FORBIDDEN_ELEM)
		ft_putstr("Error:\n Wrong elements in map.\n");
	if (exit_code == ERROR_NO_WALLS)
		ft_putstr("Error:\n Walls are not enclosed.\n");
	if (exit_code == ERROR_NO_PLAYER)
		ft_putstr("Error:\n No players.\n");
	if (exit_code == ERROR_DUPLIC_PLAYER)
		ft_putstr("Error:\n More than one player.\n");
	if (exit_code == ERROR_NO_ENEMY)
		ft_putstr("Error:\n Wrong enemy number.\n");
	if (exit_code == ERROR_EXIT)
		ft_putstr("Error:\n Wrong number of exits.\n");
	if (exit_code == ERROR_NO_COLLECTABLES)
		ft_putstr("Error:\n Wrong collect number.\n");
	free_if_game(game);
	exit(exit_code);
}

int	check_map(char	*map_name, t_map	*game)
{
	int	error;

	if (map_to_matrix(map_name, game) != 0)
		manage_prog_error(game, ERROR_EMPTY_FILE);
	if (check_map_name(map_name) != 0)
		manage_map_error(game, ERROR_MAP_NAME);
	if (check_rectangular(game) != 0)
		manage_map_error(game, ERROR_NO_RECT);
	if (check_elements(game) != 0)
		manage_map_error(game, ERROR_FORBIDDEN_ELEM);
	if (check_walls(game) != 0)
		manage_map_error(game, ERROR_NO_WALLS);
	error = check_player(game);
	if (error != 0)
		manage_map_error(game, error);
	count_enemy(game);
	if (check_collect(game) != 0)
		manage_map_error(game, ERROR_NO_COLLECTABLES);
	if (check_exit(game) != 0)
		manage_map_error(game, ERROR_EXIT);
	if (floodfill(game) != 0)
		manage_map_error(game, ERROR_NO_PATH);
	return (0);
}
