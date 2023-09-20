/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:57:05 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/20 14:57:05 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strdup(const char *s)
{
    int i;
    char * res;

    i = 0;
    res = (char*)malloc(len*sizeof(char));
    if (res == 0)
        return (0);
    while(s[i] != '\0')
    {
        res[i] = s[i];
        i++;
    }
    res[i] = '\0';
    return(res);
}