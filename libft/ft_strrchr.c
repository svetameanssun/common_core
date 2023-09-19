/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:29:04 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/19 19:46:09 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int count;
	char *aux;

	count = ft_strlen((char *)s) - 1;
	aux = (char *)s;
	if (s[count] == '\0')
	{
		return (NULL);
	}
	while (count >= 0)
	{
		if (c == aux[count])
			return (aux + count);
		count--;
	}
	return (NULL);
}