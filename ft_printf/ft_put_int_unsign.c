/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int_unsign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:03:43 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/28 14:18:12 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_unsign(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	int_putnbr_unsign(unsigned int n)
{
	int	count;

	count = count_digits_unsign(n);
	if (n >= 10)
	{
		int_putnbr(n / 10);
	}
	int_putchar(n % 10 + '0');
	return (count);
}
