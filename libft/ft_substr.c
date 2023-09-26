/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:56:07 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/26 21:43:10 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
/*#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>*/

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
    new = malloc(sizeof(char)*(len + 1));
    if (new == NULL)
        {free(new);
		return (NULL);}
    if (s == NULL)
        {free(new);
        return ((char*)s);}
    if (start >  s_len)
        {free(new);
        return (ft_strdup(""));}
    /*if (start > s_len)
        return ((char*)s);
        esto segun paco da igual*/
        
    i = 0;
    
    while ((i + (size_t)start < (size_t)start + len) && (i < s_len) /*&& start < s_lenesto tmb*/)
        {
            new[i] = s[i + (size_t)start];
            i++;
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
    return 1;
}*/