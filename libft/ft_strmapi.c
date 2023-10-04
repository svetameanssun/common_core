/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:49:33 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/03 15:49:33 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *res;
    unsigned int i;

    res = malloc(sizeof(char)*(ft_strlen(s) + 1));
    if (res == NULL)
        return (NULL);
    i = 0;
    while (s[i] != '\0')
    {
        res[i] = (*f)(i,s[i]);
        i++;
    }
    res[i] = '\0';
    return (res);
}
