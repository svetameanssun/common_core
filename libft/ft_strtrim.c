/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:51:05 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/29 14:01:30 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s1_len;

	if (!s1 || !set)
		return (0);
	if (s1[0] == '\0' && set[0] == '\0')
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && ft_strchr(set, s1[s1_len]))
		s1_len--;
	res = ft_substr(s1, 0, s1_len + 1);
	return (res);
}
/*int	main(void)
{
	char *s1;
	s1 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char *s2;
	s2 = "Hello \t  Please\n Trim me !";
	printf("%s", ft_strtrim(s1, s2));
	return (0);
}*/