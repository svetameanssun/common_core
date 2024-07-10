/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_enem_and_collect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:23:19 by stitovsk          #+#    #+#             */
/*   Updated: 2024/07/10 17:23:20 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void count_enemy(t_map * game)
{
    int i;
    int j;

    i  = 0;
    j = 0;
    while(game->matrix[i])
    {
        j = 0;
        while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
        {
            game->n_enemies+= is_elem(game->matrix[i][j],'N');
            j++;
        }
        i++;
    }
    return ;
}

int check_collect(t_map * game)
{
    int i;
    int j;

    i = 0;
    while(game->matrix[i])
    {
        j = 0;
        while(game->matrix[i][j] != '\0' && game->matrix[i][j] != '\n')
        {
            game->n_collects += is_elem(game->matrix[i][j],'C');
            j++;
        }
        i++;
    }  
    if (game->n_collects < 1)
        return(ERROR_NO_COLLECTABLES);
    return(0);
}

