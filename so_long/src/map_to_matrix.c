/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:53:39 by svetameanss       #+#    #+#             */
/*   Updated: 2024/07/07 17:55:47 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_print_matrix(char **matrix)
{

    while(*matrix)
    {
        ft_printf("%s\n", *matrix);
        matrix++;
    }
}


int map_to_matrix(char *map_name, t_map *game)
{
    int lines_num;
    int fd;
    int i;

    lines_num = count_map_lines(map_name);
    if (lines_num == 0)
        return(ERROR_EMPTY_FILE);
    game->map_dim.y = lines_num;
    fd = open(map_name,O_RDONLY);
    if (fd < 0)
        manage_prog_error(game, ERROR_FD);
    game->matrix = (char **)malloc(sizeof(char*) * (lines_num + 1));
    if(game->matrix == NULL)
        manage_prog_error(game, ERROR_MALLOC);
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