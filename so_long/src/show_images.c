#include "../include/so_long.h"

static void	ft_displ_wall_floor(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < game->map_dim.y)
	{
		while (++j < game->map_dim.x)
		{
			if (game->matrix[i][j] == '1')
			{
				mlx_image_to_window(game->mlx, game->images.wall, j * PIX, i * PIX);
			}
			if (game->matrix[i][j] == '0' || game->matrix[i][j] == 'P'
				|| game->matrix[i][j] == 'C' || game->matrix[i][j] == 'E'
                || game->matrix[i][j] == 'N')
			{
				mlx_image_to_window(game->mlx, game->images.floor, j * PIX, i * PIX);
			}
		}
		j = -1;
	}
	//mlx_image_to_window(d->mlx, d->images.chest, 1, 1);
}

static void	ft_displ_collec(t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->n_collects)
	{
		mlx_image_to_window(game->mlx, game->images.collect, game->coll_pos[i].x * PIX, game->coll_pos[i].y * PIX);
		//mlx_image_to_window(game->mlx, game->images.floor, game->co[i].x * P, game->co[i].y * P);
		//mlx_image_to_window(game->mlx, game->im.pol, game->co[i].x * P, game->co[i].y * P);
		//game->images.collect->instances[i].enabled = false;
	}	
}

static void	ft_displ_exit(t_map *game)
{
	mlx_image_to_window(game->mlx, game->images.exit, game->exit.x * PIX, game->exit.y * PIX);
	//mlx_image_to_window(game->mlx, game->im.hiv, game->exi.x * P, game->exi.y * P);
	//game->images.exit->instances[0].enabled = false;
}

static void	ft_displ_player(t_map *game)
{
	mlx_image_to_window(game->mlx, game->images.player_right, game->player.x * PIX, game->player.y * PIX);
}
static void	ft_displ_enemies(t_map *game)
{
	int	i;

	i = -1;
	while (++i < game->n_enemies)
	{
		
		mlx_image_to_window(game->mlx, game->images.enemy_left, game->enemies_pos[i].x * PIX, game->enemies_pos[i].y * PIX);
		//mlx_image_to_window(game->mlx, game->images.floor, game->co[i].x * P, game->co[i].y * P);
		//mlx_image_to_window(game->mlx, game->im.pol, game->co[i].x * P, game->co[i].y * P);
		//game->images.collect->instances[i].enabled = false;
	}	
}

/**
 * @brief DISPLAy:
 * 		'1'->wall / '0'->floor / 'P'->player / 'C'->collec
 * 
 * @param game 
 */
void	show_images(t_map *game)
{
	ft_displ_wall_floor(game);
	ft_displ_collec(game);
	ft_displ_exit(game);
	ft_displ_player(game);
	ft_displ_enemies(game);
}