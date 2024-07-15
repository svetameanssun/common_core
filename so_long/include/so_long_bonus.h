/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:32:42 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/15 17:51:28 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "MLX42.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define PIX 200
# define SECONDS 0.03

# define ERROR_MAP_NAME 1

# define ERROR_NO_RECT 2
# define ERROR_FORBIDDEN_ELEM 3
# define ERROR_NO_WALLS 4
# define ERROR_NO_PLAYER 5
# define ERROR_EXIT 6
# define ERROR_NO_COLLECTABLES 7
# define ERROR_INPUT 8
# define ERROR_NO_PATH 9
# define ERROR_MALLOC 10
# define ERROR_FD 11
# define ERROR_DUPLIC_PLAYER 12
# define ERROR_NO_ENEMY 13
# define ERROR_EMPTY_FILE 14
# define ERROR_MLX 15
# define ERROR_SIZE 16
# define ERROR_LOC 17

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit_opened;
	mlx_image_t	*exit_closed;
	mlx_image_t	*player_left_up;
	mlx_image_t	*player_right_up;
	mlx_image_t	*player_left_down;
	mlx_image_t	*player_right_down;
	mlx_image_t	*enemy_left;
	mlx_image_t	*enemy_right;
	mlx_image_t	*collect;
}	t_images;

typedef struct s_texture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*exit_opened;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*player_left_up;
	mlx_texture_t	*player_right_up;
	mlx_texture_t	*player_left_down;
	mlx_texture_t	*player_right_down;
	mlx_texture_t	*enemy_left;
	mlx_texture_t	*enemy_right;
	mlx_texture_t	*collect;
}	t_textures;

typedef struct s_map
{
	char		**matrix;
	t_point		map_dim;
	t_point		player_pos;
	t_point		exit_pos;
	int			n_collects;
	int			n_enemies;
	int			moves;
	mlx_t		*mlx;
	t_images	images;
	mlx_image_t	*movmnts;
	t_textures	textures;
}	t_map;

/* ************************************************************* */
/*    GET_NEXT_LINE FUNCTIONS & READING THE MAP FROM THE FILE    */
/* ************************************************************* */

size_t		ft_strlen_gnl(const char *str);
char		*ft_strjoin_gnl(char *s1, char *s2);
char		*ft_strncpy_gnl(char *dest, char *src, size_t n);
int			count_till_nl(char *str);
int			count_after_nl(char *str);
int			check_nl_escape(char *str);
char		*copy_first_line(char *str);
char		*read_all(int fd, char *str);
char		*update_statik_str(char *old_str);
char		*get_next_line(int fd);

/* ************************************************************* */
/*             CHECKING MAP & MAP NAME FROM FILE                 */
/* ************************************************************* */
/**
 * @brief Checks whether only allowed charachters in map used
 *              1 - wall,
 * 				0 - free spaces,
 * 				C - collectibles,
 *              P - player,
 * 				E - exit,
 * 				N - enemy
 * @param data  receives t_map as a param
 * 
 * @return returns(0) - only allowed chars; returns(1) - not allowed chars;
*/
int			check_elements(t_map *game);

/**
 * @brief Checks the ammount of players, saves player position (x,y);
 * @return returns(0) - success, returns(1) - failure
 * @param data t_map *game                  
*/
int			check_player(t_map *game);

int			check_exit(t_map *game);
/**
 * @brief Checks the number of collectibles to be >= 1.
 *        Saves number of collectibles in game->n_collects
 * @return returns(0) - success, returns(1) - failure		
 * @param data t_map *game                   
*/
int			check_collect(t_map *game);

void		count_enemy(t_map *game);

/**
 * @brief Checks the filename, where the maps is saved      
 * @return returns(0) - success, returns(1) - failure
 * @param  data char *map_name
*/
int			check_map_name(char *map_name);

/**
 * @brief Checks whether the lines in map_matrix
 * 		  are the same length. Take into account '\n'
 *        except for the last line.
 * @return returns(0) - success, returns(1) - failure
 * @param data t_map * game  
*/
int			check_rectangular(t_map *game);

/**
 * @brief Checks if all the positions of the 1st and last line
 *        & 1st and last column equal 1. DOES NOT check whether
 * 		  a collectible is enclosed (check fillflood for that).
 * 		  Saves nbr of columns in game->map_dim.x
 * @return returns(0) - success, returns(1) - failure
 * 					
 * 
 * @param data t_map *game
 */
int			check_walls(t_map *game);

/**
 * @brief Opens a file and copies all the lines from it
 		  into a char **matrix using get_next_line.
		  Saves nbr of rows in game->map_dim.y
 * @return returns(0) - success, returns(1) - failure				
 * @param data t_map * game, t_map *game      
*/
int			map_to_matrix(char *map_name, t_map *game);

/* ************************************************************* */
/*                           FLOODFILL                           */
/* ************************************************************* */
char		*fill(char **map, int rows, int columns);
int			part_floodfill(char	**copymap, t_map *game);
int			floodfill(t_map *game);

/* ************************************************************* */
/*           MANAGE ERRORS & FREE STRUCT & FREE MATRIX           */
/* ************************************************************* */
/**
 * @brief Applies all the functions described before.
 * If some function does not return 0, the function
 * manages error with manage_prog_error() or manage_map_error();         
 * @return returns(0) - success, returns(EXIT_CODE)
 * @param data char * map_game, t_map *game                 
*/
int			check_map(char *map_name, t_map *game);

/**
 * @brief Used in check_map, depending on what exit code the valid_map has,
 * 		  this writes specific message in stderr. Uses FREE_IF_GAME
 * @return returns the exit code hat entered as a parameter
 * @param data int exit_code & t_map *game	
*/
void		manage_map_error(t_map *game, int exit_code);

/**
 * @brief Used in check_map, depending on what exit code the valid_map has,
 * 		  this writes specific message in stderr. Uses FREE_IF_GAME
 * @return returns the exit code hat entered as a parameter
 * @param data int exit_code & t_map *game	
*/
void		manage_prog_error(t_map *game, int exit_code);

/**
 * @brief If game is created, remove matrix
 * @param data t_map *game
 */
void		free_if_game(t_map *game);

/**
 * @brief Frees a bidimentional array of chars
 * @param data char **map
*/
void		free_matrix(char **map);

/* ************************************************************* */
/*                    AUXILIARY FUNCTIONS                        */
/* ************************************************************* */
/**
 * @brief Auxiliary function, compares 2 chars.
 * @return returns (1) if equal, returns (0) if NOT equal
 * @param data int c, int elem				
*/
int			is_elem(int c, int elem);

/**
 * @brief Counts lines in a file, file name enters as a param.
 *        It uses GET_NEXT_LINE;
 * @return returns number of lines
 * @param data int c, int elem		
*/
int			count_map_lines(char *map_name);

/**
 * @brief Prints a bidimentional array of chars.
 *		  Uses FT_PRINTF
 * @param data char **matrix
*/
void		ft_print_matrix(char **matrix);
void		n_to_one(char **copymap);
size_t		ft_strlen_sl(const char *str);

/* ************************************************************* */
/*              GAME INITIATION & GAME UPDATE                    */
/* ************************************************************* */
void		init_game(t_map *game);
void		update_game(t_map *game);
void		update_enemy(t_map *game);
void		update_collectables(t_map *game);
void		player_current_pos(t_map *game);
void		textures_to_img(t_map *game);
void		create_playwindow(t_map *game);
void		show_map(t_map *game);
int32_t		show_window(t_map *data);

/* ************************************************************* */
/*                        MANAGE KEYS                            */
/* ************************************************************* */
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		key_w(t_map *game);
void		key_s(t_map *game);
void		key_d(t_map *game);
void		key_a(t_map *game);
void		all_moves(mlx_key_data_t k, t_map *game);

/* ************************************************************* */
/*       LOAD TEXTURES & IMAGES, DELETE TEXTURE & IMAGES         */
/* ************************************************************* */
mlx_image_t	*get_image(t_map *game, mlx_image_t	*img, char symbol);
void		load_players(t_map *game, mlx_image_t *img, int x, int y);
void		load_enemies( t_map *game, mlx_image_t *img, int x, int y);
void		load_elem(t_map *game, int x, int y, char symbol);
void		load_textures(t_map	*game);
void		delete_textures(t_map *game);
void		delete_img(t_map *game);
void		check_texture(t_map	*game, mlx_texture_t **txt, char *str);

#endif
