/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:17 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/26 18:17:21 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	
	statik = read_till_nl(fd, statik);
	line = copy_first_line(statik);
	statik = update_statik_str(statik);

	return (line);

}

int main()
{
    int fd_open = open("file_to_read.txt", O_RDONLY);
	printf("%s", get_next_line(fd_open));
	retrun(0);
    /*char *str;
	str = malloc(1 * (7));
	int i = 0;
	while(i < 7)
	{
		str[i] = 'a';
		i++;
	}
	str[3] = '\n';
	int before = count_till_nl(str);
	int after = count_after_nl(str);
	printf("%d\n", before);
	printf("%d\n", after);
	printf("%s\n",str);
	str = update_statik_str(str);
	printf("%s",str);*/

    
}