/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:27:12 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 17:01:22 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (n == 0)
		return (dst);
	if (src < dst)
	{
		i = n;
		while (--i >= 0)
		{
			*(dest + i) = *(source + i);
		}
	}
	else if (src > dst)
	{
		i = -1;
		while (++i < (int)n)
		{
			*(dest + i) = *(source + i);
		}
	}
	return (dst);
}
