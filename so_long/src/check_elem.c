/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:05:46 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/11 21:30:57 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_elem(char ** map_matrix, int i)
{
    int j;
    int collect;
    int player;
    int exit;
    int enemy;

    i = 0;
    j = 0;
    collect = 0;

    while(map_matrix[i])
    {
        j = 0;
        while(map_matrix[i][j])
        {
            if (map_matrix[i][j] == 'C')
                collect++;
            else if (map_matrix[i][j] == 'E')
                exit++;
            else if (map_matrix[i][j] == 'P')
                player++;
            else if (map_matrix[i][j] == 'N')
                enemy++;
            j++;
        }
        i++;
    }
    if (collect < 1 || exit != 1 || player != 1 || enemy < 1)
        return(1);
    return(0);
    
}

/*int main()
{
    char **split_str;
	char str[] = {"11111111,10000001,1P000001,10000E01,1000N001,10000001,10000001,11111111"};
	split_str = ft_split(str,',');
	printf("%d", check_elem(split_str, 0));
	return(0);
}*/