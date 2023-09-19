/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:41:33 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/19 20:32:09 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	char *aux;

	i = 0;
	aux = (char *)s;
	if (s[i] == '\0')
	{
		return (aux);
	}
	while (s[i] != '\0')
	{
		if (aux[i] == c)
		{
			return (aux + i);
		}
		i++;
	}
	return (NULL);
}