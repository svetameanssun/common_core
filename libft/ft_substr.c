/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:56:07 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/26 18:54:53 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/*size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}*/

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, &s[start], len);
	str[len] = 0;
	return (str);
}*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    size_t          s_len;
    char            *new;

    s_len = (strlen(s));
    new = malloc(sizeof(char) * (len + 1));
    if (new == NULL)
		return (NULL);
    if (s == NULL)
        return (NULL);
    if (start >  s_len)
        return ("");
    if (len > ft_strlen(new))
        len = ft_strlen(new);
    i = 0;
    if (s_len <= len)
    {
        while(i + (size_t)start < s_len)
        {
            new[i] = s[i + (size_t)start];
            i++;
        }
    }
    else if (s_len > len)
    {
        while ((i + (size_t)start < (size_t)start + len) && (i < s_len))
        {
            new[i] = s[i + (size_t)start];
            i++;
        }
    }
    new[i] = '\0';
    return (new); 
}

/*int main (void)
{
    char *str = "i just want this part #############";
    size_t size = 22;
    char *ret = ft_substr("", 0, 0);
 
    printf("%s", ret);
}*/
/*int main (void)
{
    char * res;
    res = "";
    printf("%zu", ft_strlen(res));
    return 1;
}*/