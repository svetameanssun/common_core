/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:03:52 by stitovsk          #+#    #+#             */
/*   Updated: 2023/12/01 19:18:55 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_hex(long unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	int_puthex(char c, long unsigned int n)
{
	char	*base;
	int		count;

	count = count_hex(n);
	if (c == 'X')
		base = "0123456789ABCDEF";
	else if (c == 'x')
		base = "0123456789abcdef";
	if (n == 0)
		write(1, &base[0], 1);
	else if (n >= 16)
	{
		int_puthex(c, n / 16);
		int_puthex(c, n % 16);
	}
	else
		write(1, &base[n], 1);
	return (count);
}
int	int_putptr(long unsigned int n)
{
	return (write(1, "0x", 2) + int_puthex('x', n));
}
