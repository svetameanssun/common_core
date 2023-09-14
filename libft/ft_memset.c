/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:12:50 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/14 17:43:22 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, int n)
{
	int	i;
    unsigned char *tmp;
    
	i = 0;
    tmp = s;
	while (i < n)
	{
    	tmp[i] = (unsigned char)c;
	    i++;
	}
	return (s);
}
