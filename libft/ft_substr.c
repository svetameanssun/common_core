/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:56:07 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/25 21:43:34 by stitovsk         ###   ########.fr       */
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

/*char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char            *new;
    unsigned int    i;
    unsigned int    s_len;

    s_len = ft_strlen(s);
    if (start > s_len)
        return ("");
    new = (char*)malloc(sizeof(char) * len + 1);
    if (new == NULL)
		return (NULL);
    i = 0;
    while(s[i] != '\0' && i < len)
    {
        new[i] = s[i + start];
        i++;
    }
    new[i] = '\0';
    return (0);
}*/
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    size_t          s_len;
    char            *new;

    s_len = (strlen(s));
    new = (char*)malloc(sizeof(char) * len + 1);
    if (new == NULL)
		return (NULL);

    if (s == 0)
        return (0);
    if (start >  (unsigned int)s_len)
        return ("");
    i = 0;
    if (s_len <= len)
    {
        while(i + start < (unsigned int)s_len)
        {
            new[i] = s[i + start];
            i++;
        }
    }
    else if (s_len > len)
    {
        while ((i + start < start + len) && (i < s_len))
        {
            new[i] = s[i + start];
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
    char *ret = ft_substr(str, 0, size);
 
    if (!strncmp(ret, str, size))
    {
        free(ret);
        exit(1);
    }
    free(ret);
    exit(0);
    return 0;
}*/