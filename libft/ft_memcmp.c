/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:49:22 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 13:24:15 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	cont;

	cont = 0;
	while (cont < n)
	{
		if (*((unsigned char *)s1 + cont) != *((unsigned char *)s2 + cont))
			return (*((unsigned char *)s1 + cont) - *((unsigned char *)s2
					+ cont));
		cont++;
	}
	return (0);
}
