/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:27:12 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 13:43:47 by stitovsk         ###   ########.fr       */
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
		i = n - 1;
		while (i >= 0)
		{
			*(dest + i) = *(source + i);
			i--;
		}
	}
	else if (src > dst)
	{
		i = 0;
		while (i < (int)n)
		{
			*(dest + i) = *(source + i);
			i++;
		}
	}
	return (dst);
}
