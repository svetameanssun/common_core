/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marigome <marigome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:54:12 by marigome          #+#    #+#             */
/*   Updated: 2025/02/25 17:59:11 by marigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	first = 0;
	if (!s1 || !set)
		return (NULL);
	while (*(s1 + first) && ft_strchr(set, *(s1 + first)))
		first++;
	last = ft_strlen(s1);
	while (last > first && ft_strchr(set, *(s1 + (last - 1))))
		last--;
	return (ft_substr(s1, first, (last - first)));
}

/*int	main(void)
{
	char	s1[] = "  Holaquepasa  ";
	char	set[] = " ";
	printf("%s", ft_strtrim(s1, set));

	return (0);
}*/