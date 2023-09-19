/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:07:21 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/19 14:07:21 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*       If little is an empty string, big is returned; if little	occurs nowhere
       in big, NULL is returned; otherwise a pointer to	the first character of
       the first occurrence of little is returned.*/

char *ft_strnstr(const char *big,	const char *little, size_t len)
{
    size_t i;
    size_t little_len;

    
    little_len = ft_strlen(little);
    if(little_len == 0)
        return ((char *)big);
    i = 0;
    while (i + little_len <= len)
}