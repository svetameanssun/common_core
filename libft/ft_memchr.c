/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:48:46 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/19 12:48:46 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned *char aux;

    i = 0;
    aux = s;
    while(i < n)
    {
        if(aux[i] == (unsigned char)c)
            return (aux + i);
        i++;
    }
    return (NULL);
}