/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:47:41 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/20 11:47:41 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *calloc(size_t nelem, size_t elsize)
{
    size_t i;
    void *res;

    i = 0;
    res = malloc(nelem * elsize);
    if (res!= 0)
    { 
        return(ft_memset(res, 0, nelem*elsize));
    }
    return (0);
}
