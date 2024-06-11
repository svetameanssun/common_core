/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_map_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:35:15 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/11 22:58:08 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int count_map_lines(char * map_name)
{
	int count;
	char *str;
    int fd;

	fd = open(map_name, O_RDONLY);
    if (fd < 0)
        return(0);
	str = get_next_line(fd);
	free(str);
    count = 0;
    while(str)
    {
        str = get_next_line(fd);
		free(str);
		count++;
    }
    close(fd);
    return(count);
}

/*int main(int argc, char **argv)
{
	printf("%d", count_map_lines(argv[1]));
	return(0);
    
}*/