/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:03:55 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/24 17:38:28 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_putchar(char c)
{
	write(1, &c, 1);
    return(1);
}

int	int_putstr(char *str)
{
    int count;

    count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
        count++;
	}
    return(count);
}