/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:30:37 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 16:57:45 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

size_t	ft_strlen2(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen2(s);
	str = (char *) malloc((j + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlcpy2(char *dest, const char *src, size_t size)
{
	size_t			i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
		count++;
	if (size < 1)
		return (count);
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*str3;
	int		totallen;
	int		i;
	int		j;

	totallen = ft_strlen2(s1) + ft_strlen2(s2);
	i = 0;
	j = 0;
	str3 = (char *) malloc((totallen + 1) * sizeof(char));
	if (!str3)
		return (0);
	while (s1[i] != '\0')
	{
		str3[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str3[i] = s2[j];
		i++;
		j++;
	}
	str3[i] = '\0';
	return (str3);
}

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen2(s))
		return (ft_strdup2(""));
	if (len > ft_strlen2(s + start))
		len = ft_strlen2(s + start);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy2(str, (s + start), len + 1);
	return (str);
}
