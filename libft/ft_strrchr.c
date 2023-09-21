/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:29:04 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/21 18:23:01 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int i;
	char *aux;
	
	i = 0;
	aux = NULL;

	while(s[i] != '\0')
	{
		if(s[i] == (unsigned char)c)
			aux = (char *)s + i;
		i++;
	}
	if (c == 0)
		aux = (char *)s + i;
	return (aux);
}