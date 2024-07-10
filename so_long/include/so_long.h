/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:29:46 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/10 18:02:19 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../MLX42/include/MLX42/MLX42.h"

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



typedef struct s_point
{
	int x;
	int y;
	
} t_point;

typedef struct s_images
{
	mlx_image_t *floor;
	mlx_image_t *wall;
	
	mlx_image_t *exit_opened;
	mlx_image_t *exit_closed;

	mlx_image_t *player_left_up;
	mlx_image_t *player_right_up;
	mlx_image_t *player_left_down;
	mlx_image_t *player_right_down;
	
	mlx_image_t *enemy_left;
	mlx_image_t *enemy_right;
	mlx_image_t *collect;
} 					t_images;

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
}		t_textures;

typedef struct s_map
{
	char ** matrix;
	t_point map_dim;
	t_point player_pos;
	t_point exit_pos;

	int n_collects;
	int n_collected;
	int n_enemies;
	
	int moves;
	mlx_t *mlx;
	t_images images;
	mlx_image_t *movmnts;
	t_textures textures;
	
} t_map;


/* ************************************************************* */
/* ********        GET_NEXT_LINE FUNCTIONS        ************** */
/* ********    & READING THE MAP FROM THE FILE    ************** */
/* ************************************************************* */

/** 
 * @brief defines the length of the string (used for get_next_line)
 * 
 * @param data const char *str
*/
size_t	ft_strlen_gnl(const char *str);

/**
 * @brief joins strings that enter as the parameter (s1 + s2)
 *                                   (used for get_next_line)
 * 
 * @param data char *s1, char *s2
*/
char	*ft_strjoin_gnl(char *s1, char *s2);

/**
 * @brief copies n number of chars from source string till
 * destination string, if the source string doesn't finish before.
 * 
 * @param data char *dest, char *src, size_t n                     
*/
char	*ft_strncpy_gnl(char *dest, char *src, size_t n);
int		count_till_nl(char *str);
int		count_after_nl(char *str);
int		check_nl_escape(char *str);
char	*copy_first_line(char *str);
char	*read_all(int fd, char *str);
char	*update_statik_str(char *old_str);
char	*get_next_line(int fd);


/* ************************************************************* */
/* ********   CHECKING THE MAP & THE MAP NAME     ************** */
/* ********           FROM THE FILE               ************** */
/* ************************************************************* */



/**
 * @brief       checks whether only allowed charachters in map used
 *              1 - wall, 0 - free spaces, C - collectibles,
 *              P - player, E - exit, N - enemy
 * 
 * @return          returns(0) - only allowed chars
 *                  returns(1) - not allowed chars
 * 
 * @param data      	receives t_map as a param
*/
int check_elements(t_map * game);

/**
 * @brief		checks 1 player and 1 or more enemies
 * 					!!! for the moment I left only one enemy as the correct one
 * 					JUST IN CASE (if I will not do the enemy afterall)!!!
 *              player == 1, enemy == 1,
 *   
 * 
 * @return          returns(0) - success
 *                  returns(1) - failure
 *					saves player position (x,y);
 * 
 * @param data      t_map *game                  
*/
int check_player(t_map * game);
int check_exit(t_map * game);
int	check_exit_access(t_map *game);

/**
 * @brief		checks the number of elements and characters,
 *              whether it is allowed number.
 *              collectibles >= 1, player == 1, enemy == 1,
 *              exit == 1
 * 
 * @return          returns(0) - success
 *                  returns(1) - failure
 * 					saves number of collectibles in game->n_collects
 * 
 * @param data     		t_map *game
 *                       
*/
int check_collect(t_map * game);

void count_enemy(t_map * game);


/**
 * @brief		checks whether the filename of the file
 *             	where the maps is saved
 *              !!! ADD cond if file_name length <= 4 !!!
 *
 * @return          returns(0) - success
 *                  returns(1) - failure
 * 
 * @param  data         the map_name
 * 
*/
int check_map_name(char *map_name);


/**
 * @brief       checks whether the lines in map_matrix
 *              are the same length. Take into account '\n'
 *              except for the last line.
 * 
 * @return          returns(0) - success
 *                  returns(1) - failure
 * 
 * @param  data  		receives t_map* as a param
 *              
*/
int check_rectangular(t_map * game);

/**
 * @brief       checks if all the positions of
 *              the 1st and last line
 *              & 1st and last column
 *              equal 1
 *         DOES NOT check whether a collectible is enclosed
 *         (check fillflood for that)     
 *
 * @return          returns(0) - success
 *                  returns(1) - failure
 * 					saves nbr of columns in game->map_dim.x
 * 
 * @param data   receives t_map* as a param
*/
int check_walls(t_map * game);

/**
 * @brief        opens a file "map_name"
 *               and copies all the lines from it
 *               into a char **matrix using get_next_line
 * 
 * @return          returns(0) - success
 *                  returns(1) - failure
 * 					saves nbr of rows in game->map_dim.y         
*/
int map_to_matrix(char *map_name, t_map *game);

/**
 * @brief       applies all the functions described before
 *              
 * @return          returns(0) - success
 *              	returns(1) - wrong file name            
 *              	returns(2) - not rectangular           
 *              	returns(3) - not allowed chars
 *              	returns(4) - walls are not enclosed
 *              	returns(5) - the number of element is not correct!           
*/
int check_map(char * map_name, t_map *game);

/**
 * @brief		auxiliary function, that compare
 * 				2 chars.
 * @return		returns 1 if equal
 *				returns 0 if NOT equal
*/
int is_elem(int c, int elem);

/**
 * @brief		counts lines in a file,
 * 				file name enters as a param.
 * 				It uses GET_NEXT_LINE;
 * 			
*/
int count_map_lines(char * map_name);


/**
 * @brief		used in valid_map, depending on
 * 				what exit code the valid_map has,
 * 				this writes specific message in stderr
 * 				
 * @return			returns the exit code
 * 					that entered as a parameter
 * 
 * @param data 			int exit_code & t_map *game
 * 						to free game.	
 * 
*/
void manage_map_error(t_map *game, int exit_code);
void manage_prog_error(t_map *game, int exit_code);
//void manage_game_error(t_map *game, int exit_code);
void free_if_game(t_map *game);




/**
 * @brief		in theory should free a structure t_map
 * 				but I think in the end I will not need it,
 * 				because I will create a var t_map game,
 * 				and not a pointer t_map * game,
 * 				no need for malloc, no need to free.
 * 
 * @param data		takes in the structure it will free
 * 						
*/

/**
 * @brief			frees a bidimentional array
 * 
 * @param data		takes the bidemntional array as a parameter	
*/
void	free_matrix(char **map);
void ft_print_matrix(char **matrix); // REMOVE OR CHANGE




void	init_game(t_map *game);

void n_to_one(char **copymap);
char	*fill(char **map, int rows, int columns);
int	part_floodfill(char	**copymap, t_map *game);
int	floodfill(t_map *game);
void	player_current_pos(t_map *game);
//t_point *find_collects(t_map *game);

void	load_textures(t_map	*game);
void	textures_to_img(t_map *game);
void	create_playwindow(t_map *game);
void	delete_textures(t_map *game);
void	delete_img(t_map *game);

void	show_map(t_map	*game);
int32_t	show_window(t_map *data);
void load_elem(t_map *game, int x, int y, char symbol);
mlx_image_t	*get_image(t_map *game, char symbol);




void my_keyhook(mlx_key_data_t keydata, void *param);
void key_w(t_map * game);
void key_s(t_map * game);
void key_d(t_map * game);
void key_a(t_map * game);


void	update_game(t_map *game);
void	update_enemy(t_map *game);
void	update_collectables(t_map *game);
size_t	ft_strlen_sl(const char *str); //the 3rd strlen in the project

# endif