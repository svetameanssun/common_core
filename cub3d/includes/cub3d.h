/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:38:05 by marigome          #+#    #+#             */
/*   Updated: 2025/02/27 13:45:05 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h> // To use perror, errno
# include <fcntl.h> // To use open, close
# include <math.h>  // Math functions
# include <stdio.h>
# include <stdlib.h> // To use malloc, free
# include <string.h> // To use strlen, strdup
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "get_next_line_bonus.h"
# include "colors.h"
# include "macro.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_texture
{
	char			*no_path;		// the path of the north texture
	char			*so_path;		// the path of the south texture
	char			*we_path;		// the path of the west texture
	char			*ea_path;		// the path of the east texture
	int				no_flag;		// the flag of the north texture
	int				so_flag;		// the flag of the south texture
	int				we_flag;		// the flag of the west texture
	int				ea_flag;		// the flag of the east texture
	int				color_flag;			// the flag of the ceiling color
	int				floor_flag;			// the flag of the floor color
	unsigned int	ceiling_color;		// the color of the ceiling
	unsigned int	floor_color;		// the color of the floor
	mlx_texture_t	*no_texture;	// the north texture
	mlx_texture_t	*so_texture;	// the south texture
	mlx_texture_t	*we_texture;	// the west texture
	mlx_texture_t	*ea_texture;	// the east texture
}	t_texture;

typedef struct s_point
{
	int	x;							//the x coordinate of the point to draw
	int	y;							//the y coordinate of the point to draw
}	t_point;

typedef struct s_line
{
	int	x;				// the x coordinate of line relative to screen
	int	y;				// the current pixel index of the line (along y axis)
	int	y_start;		// y start index of drawing texture
	int	y_end;			// y end index of drawing texture
	int	texture_x;			// x coordinate of texture to draw
	int	texture_y;			// y coordinate of texture to draw
}	t_line;

typedef struct s_ray
{
	int			flag; // Flag used when the ray touches the wall;
	int			x_map;
	int			y_map;
	double		angle;
	double		angle_ret;
	double		x_player_pos;
	double		y_player_pos;
	double		ray_x;
	double		ray_y;
	double		ray_dist_to_x;
	double		ray_dist_to_y;
	double		cell_crossing_dist_x;
	double		cell_crossing_dist_y;
	double		current_side_dist_x;
	double		current_side_dist_y;
	double		wall_ray_hit_dist;
	double		wall_visible_height;
	double		texture_coord;
	double		ray_hypoteneuse_dist;
	double		vertical_ray_travel;
	double		ray_move_x;
	double		ray_move_y;
}				t_ray;

typedef struct s_player
{
	double		angle;// Ángulo de visión del jugador
	double		pos_player_x;
	double		pos_player_y;// Movimiento del jugador en X/Y
	int			map_x;
	int			map_y;
	t_ray		ray[WIDTH];
}	t_player;

typedef struct s_map
{
	char			**map;					// the map of the game
	int				x_map;				// the size of the map in x
	int				y_map;				// the size of the map in y
	int				map_line;				// the line of the map
}	t_map;

typedef struct s_data
{
	int				ray_number;// Número de rayos
	int				move;// Flag de movimiento
	char			*file;// Archivo del mapa
	t_map			map;// Información del mapa
	t_player		player;// Jugador
	t_texture		textures;// Texturas del juego
	mlx_t			*mlx;// Instancia MLX
	mlx_image_t		*image;// Imagen del fondo
	mlx_image_t		*walls;// Imagen de las paredes
}	t_data;

// ----- Functions ---------------------------------------------------------- //

/* INIT STRUCTURES */
int				ft_init_info_game(t_data *info);

/* WALLS & RAYS */
void			ft_walls(t_data *data, mlx_image_t **img);

// Textures //
int				ft_check_file(char *file, char *img, int i);
int				ft_get_walls(t_data *info, int *fd, int *res);
int				ft_update_textures(t_data *info, int *res, int *fd);

// MAP.C//
int				ft_process_line(char ***tokens, int fd);
void			ft_checker_textures(t_data *cub, char **cell);
int				ft_texture_missed(t_data *info);
void			ft_new_fd(t_data *info, int i, int *fd);
char			*ft_remove_newline(char *str);
int				ft_get_map(t_data *info, int fd);
void			print_map(t_data *info);
char			*ft_new_strjoin(char *s1, char *s2);
char			*ft_trim_str(char *s1, char *set);
int				ft_map_spliting(t_data *cub, char *map);

// CHECKER //
int				ft_check_cardinal(char **c, int i, t_data *info);
int				ft_check_path(char **c);
int				ft_check_bad_argument(char **c, int i);
int				ft_check_file(char *file, char *img, int i);
int				ft_check_colors(char **c, int i);
int				ft_check_imgs(char **c, int i, t_data *info);
int				ft_check_text(t_data *info, char **c, int *i, int line);
int				ft_check_colors_num(char **c);
int				ft_check_comma(char **c);
int				ft_checker_extension(char *file);
void			ft_store_color(t_data *info, char **c);
void			fill_ids_and_flags(const char *identifiers[4],
					int *flags[4], t_data *info);
int				ft_check_zeros(char **map);
// ERROR //
void			ft_error_color(char **path);
int				ft_strcmp(const char *s1, const char *s2);

// SPLIT //
char			*ft_realloc(char *ptr, int size);
int				ft_split_len(char **str);
void			*ft_split_free(char **str);

// MANAGE COLORS //
unsigned int	ft_rgb_get(char **c);
unsigned int	ft_rgb_to_hex(char **c);
unsigned int	ft_rgb_to_hex_split(char **c);

// PARSER //
int				ft_parse(char *cub, t_data *info);
int				ft_get_imgs_info(t_data *info, int *res, int *fd);

// FREE //
void			free_textures(t_texture *textures);
void			free_mlx_textures(t_texture *textures);
void			*free_map(char **map);

// CHECKER MAP //
int				ft_check_map(t_data *info);
int				ft_check_spaces(char **map);
int				ft_players_num(char **map);
void			ft_map_error(const char *error_type);
int				ft_check_inside(char **map);

// FULL WINDOW //
void			ft_load_png(t_data *data);
void			ft_create_image(t_data *data, mlx_image_t **image);
void			ft_player_position(t_data *data, char **map);
void			ft_init_mlx(t_data *data);
void			ft_init_play(t_data *data);

void			ft_ray_init(t_data *cub);
void			ft_print_walls_and_floor(t_data *data);
void			ft_update_moves(t_data *data);

// Calculations //
void			ft_hypo(t_ray *ray);
void			ft_size_wall_on_window(t_ray *ray);

void			ft_vert(t_data *data, t_ray *ray);
void			ft_raycasting(t_data *data, t_player *player);
void			ft_game_loop(void *info);

// Movements
int				ft_lets_move(t_data *cub, double move_x, double move_y);
void			ft_movement(t_data *cub, double angle);
// Painting
void			ft_painting_col(t_data *data, t_ray *ray, int c);

#endif
