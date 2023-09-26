/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:57:05 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/26 15:54:13 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    int             i;
    char *          res;
    unsigned int    len;
    
    len = (unsigned int)ft_strlen(s);
    i = 0;
    res = (char*)malloc(len*sizeof(char) +1);
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