/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:53:39 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/16 15:31:11 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int map_to_matrix(char *map_name, t_map *game)
{
    int lines_num;
    int fd;
    int i;

    lines_num = count_map_lines(map_name);
    game->rows = lines_num;
    fd = open(map_name,O_RDONLY);
    game->matrix = (char **)malloc(sizeof(char*) * (lines_num + 1));
    if(game->matrix == NULL)
        return(1);
    i = 0;
    while(i < lines_num)
    {   
        game->matrix[i] = get_next_line(fd);
        i++;
    }
    game->matrix[i] = NULL;
    close(fd);
    return (0);
}


//this main worked when the function returned char **
//and there was only one param (char *map_name)
/*int main(int argc, char ** argv)
{
    char ** matrix;
    matrix = map_to_matrix(argv[1]);
    ft_print_matrix(matrix);
    return(0);
}*/