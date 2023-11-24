/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:55 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/24 17:32:10 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int puthex_ptr(long unsigned int ptr, int num)
{
	char	*base;

	base = "0123456789abcdef";
	if (num > 0)
	{
		if (ptr > 15)
			puthex_ptr(ptr / 16, num - 1);
		write(1, &base[ptr % 16], 1);
	}
	return (count_hex(ptr));
}


int	int_putptr(long unsigned int n)
{
    int count;

    if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
    count = puthex_ptr(n, 16);
	return (count + 2);
}