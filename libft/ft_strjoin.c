/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:46:35 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/26 18:50:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	size_t s1_len;
	size_t s2_len;
    size_t i;

	if (!s1)
		return ((char*)s2);
    if (!s2)
		return ((char*)s1);
    
    s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
    new = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!new)
        return(NULL);
    i = 0;
    while (i < s1_len)
    {
        new[i] = s1[i];
        i++;
    }
    while (i < (s1_len + s2_len))
    {
        new[i] = s2[i - s1_len];
        i++;
    }
    new[i] = '\0';
    return (new);
}
/*int main(void)
{
    printf("%s",ft_strjoin("abcd", "efghi"));
    return 0;
    
}*/