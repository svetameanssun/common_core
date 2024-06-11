/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:23:18 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/11 21:42:02 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int check_map_name(char *map_name)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(map_name);
    /*while(i < len - 4)
    {
        if ((map_name[i] >= 33 && map_name[i] <= 39)
            || (map_name[i] >= 42 && map_name[i] <= 44)
            || (map_name[i] >= 58 && map_name[i] <= 6 )
            || (map_name[i] >= 123 && map_name[i] <= 125)
            || map_name[i] == 46 || map_name[i] == 47
            || map_name[i] == 92 || map_name[i] == 96)
            return(1);
        i++;
    }*/
    //with the while above map.berhas to be in the local directory.
    int res = ft_strncmp(map_name + (len - 4), ".ber", 4);
    if (res != 0)
        return(1);
    return(0);
}

/*int main(int argc, char **argv)
{
    
    printf("%d\n",check_map_name(argv[1]));
    printf("%d\n",check_map_name("map_name.be"));
    printf("%d\n",check_map_name("map_name.ber"));
    printf("%d\n",check_map_name("../map/name.ber"));
    return (0);
}*/