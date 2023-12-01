/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:12:50 by stitovsk          #+#    #+#             */
/*   Updated: 2023/12/01 17:48:41 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Felipe's function
void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		*((unsigned char *)(b + len)) = (unsigned char) c;
	return (b);
}
// My function
/*void	*ft_memset(void *s, size_t c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = s;
	while (i < n)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}*/
