/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:54:19 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/28 20:00:02 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    char    n;
    
    n = '\n';
    while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
    write(fd, &n, 1);
}