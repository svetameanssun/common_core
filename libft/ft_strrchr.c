/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:29:04 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/18 17:29:04 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int count;
    char *aux;

    count = ft_strlen(s) - 1;
    aux = s;
    if (s[i] == '\0')
    {
        return (NULL);
    }
    while (count >= 0)
    {
        if (c == aux[count])
            return (aux + count);
        count--;
    }
    return (NULL);
}