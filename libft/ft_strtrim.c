/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:51:05 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/28 17:55:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	little_len = (ft_strlen((char *)little));
	big_len = (ft_strlen((char *)big));
	if (little_len == 0)
		return ((char *)big);
	i = 0;
	while (i + little_len <= len && i < big_len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	s1_len;
	
	if (!s1 || !set)
		return(0);
	if (s1[0] == '\0'&& set[0] == '\0')
	{
		res  = malloc(1);
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	while (*s1 && ft_strchr(set,*s1))
		s1++;
	s1_len = ft_strlen(s1);
	while (s1_len > 0 && ft_strchr(set,s1[s1_len]))
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