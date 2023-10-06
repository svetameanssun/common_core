/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:56:07 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 13:54:03 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		new = malloc(1);
		if (!new)
			return (0);
		new[0] = '\0';
		return (new);
	}
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		new[i] = s[start];
		i++;
		start++;
	}
	new[i] = '\0';
	return (new);
}
/*int main (void)
{
	char *str = "i just want this part #############";
	size_t size = 20;
	char *ret = ft_substr(str, 5, size);

	printf("%s", ret);
}*/
/*int main (void)
{
	char * res;
	res = "";
	printf("%zu", ft_strlen(res));
	return (1);
}*/