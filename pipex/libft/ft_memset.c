/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:12:50 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/13 20:28:15 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Felipe's function
void	*ft_memset(void *s, size_t c, size_t n)
{
	while (n--)
		*((unsigned char *)(s + n)) = (unsigned char) c;
	return (s);
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
