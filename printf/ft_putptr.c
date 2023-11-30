/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:55 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/30 17:14:07 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_function(void)
{
	char *s = "Aunque no le guste a norminette, pongo un string";
	char *str = "I have created this function to keep ft_putptr";
	return;
}

int	int_putptr(long unsigned int n)
{
	return (write(1, "0x", 2) + int_puthex('x', n));
}
