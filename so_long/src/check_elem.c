/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:46 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/12 16:36:40 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int is_elem(int c, int elem)
{
    int res;

    res = 0;
    if (c == elem)
        return(1);
    return(0);
}


int check_elem(char ** map_matrix, int i, int j)
{
    int collect;
    int player;
    int exit;
    int enemy;

    collect = 0;
    player = 0;
    exit = 0;
    enemy = 0;
    while(map_matrix[i])
    {
        j = 0;
        while(map_matrix[i][j] != '\0' && map_matrix[i][j] != '\n')
        {
            collect+= is_elem(map_matrix[i][j],'C');
            exit+= is_elem(map_matrix[i][j],'E');
            player+= is_elem(map_matrix[i][j],'P');
            enemy+= is_elem(map_matrix[i][j],'N');
            j++;
        }
        i++;
    }  
    if (collect >= 1 && exit == 1 && player == 1 && enemy == 1)
        return(0);
    return(1);
}

/*int main()
{
    char **split_str;
	char str[] = {"11111111,10000001,1P000001,10000E01,1000N001,10000001,10000001,11111111"};
	split_str = ft_split(str,',');
	printf("%d", check_elem(split_str, 0));
	return(0);
}*/