#include "../include/so_long.h"

static void	ft_displ_wall_floor(t_map *d)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < d->map_dim.y)
	{
		while (++j < d->map_dim.x)
		{
			if (d->matrix[i][j] == '1')
			{
				mlx_image_to_window(d->mlx, d->images.wall, j * PIX, i * PIX);
			}
			if (d->matrix[i][j] == '0' || d->matrix[i][j] == 'P'
				|| d->matrix[i][j] == 'C' || d->matrix[i][j] == 'E'
                || d->matrix[i][j] == 'N')
				mlx_image_to_window(d->mlx, d->images.floor, j * PIX, i * PIX);
		}
		j = -1;
	}
	//mlx_image_to_window(d->mlx, d->images.chest, 1, 1);
}

static void	ft_displ_collec(t_map *d)
{
	int	i;

	i = -1;
	while (++i < d->n_collects)
	{
		mlx_image_to_window(d->mlx, d->images.collect, d->coll_pos[i].x * PIX, d->coll_pos[i].y * PIX);
		//mlx_image_to_window(d->mlx, d->im.flo, d->co[i].x * P, d->co[i].y * P);
		//mlx_image_to_window(d->mlx, d->im.pol, d->co[i].x * P, d->co[i].y * P);
		d->images.collect->instances[i].enabled = false;
	}	
}

static void	ft_displ_exit(t_map *d)
{
	mlx_image_to_window(d->mlx, d->images.exit, d->exit.x * PIX, d->exit.y * PIX);
	//mlx_image_to_window(d->mlx, d->im.hiv, d->exi.x * P, d->exi.y * P);
	d->images.exit->instances[0].enabled = false;
}

static void	ft_displ_player(t_map *d)
{
	mlx_image_to_window(d->mlx, d->images.player_right, d->player.x * PIX, d->player.y * PIX);
}

/**
 * @brief DISPLAy:
 * 		'1'->wall / '0'->floor / 'P'->player / 'C'->collec
 * 
 * @param data 
 */
void	show_images(t_map *data)
{
	ft_displ_wall_floor(data);
	ft_displ_collec(data);
	ft_displ_exit(data);
	ft_displ_player(data);
}