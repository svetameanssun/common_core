/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 22:53:39 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/11 23:25:24 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char **map_to_matrix(char *map_name)
{
    int lines_num;
    int fd;
    char **matrix;
    int i;
    lines_num = count_map_lines(map_name);
    fd = open(map_name,O_RDONLY);
    matrix = (char **)malloc(sizeof(char*) * (lines_num + 1));
    i = 0;
    while(i < lines_num)
    {
        matrix[i] = get_next_line(fd);
        i++;
    }
    matrix[i] = NULL;
    close(fd);
    return(matrix);
}

/*int main(int argc, char ** argv)
{
    char ** matrix;
    matrix = map_to_matrix(argv[1]);
    ft_print_matrix(matrix);
    return(0);
}*/