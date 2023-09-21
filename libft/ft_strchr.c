/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:41:33 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/21 15:45:33 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *aux;

	i = 0;
	aux = (char *)s;
	
	while (s[i] != (char)c)
	{
		if (!aux[i])
		{
			return (0);
		}
		i++;
	}
	return (aux + i);
}