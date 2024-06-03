/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:47:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/03 16:08:44 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*res;

	res = malloc(nelem * elsize);
	if (res != 0)
	{
		return (ft_memset(res, 0, nelem * elsize));
	}
	return (0);
}
