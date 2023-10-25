/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:17 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/25 14:08:59 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*statik;
	char		*line;
	
	statik = read_till_nl(fd, statik);
	line = copy_first_line(fd, statik);
	statik = update_statik(fd, statik);

	return (line);

}