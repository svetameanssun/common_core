/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:03:47 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/28 14:10:28 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int count_digits_int(int n)
{
    int count;

    count = 0;
    if (n == 0)
        return(1);
    if (n < 0)
    {
        n = -n;
        count++;
    }
    while(n > 0)
    {
        n = n / 10;
        count++;
    }
    return(count);   
}

int	int_putnbr(int n)
{
    int count;

    count = count_digits_int(n);
	if (n == -2147483648)
	{	write(1, "-2147483648", 11);
        return (11);
    }
    else
	{
		if (n < 0)
		{
            n = -n;
			write(1, "-", 1);
		}
		if (n >= 10)
		{
			int_putnbr(n / 10);
		}
	    int_putchar(n % 10 + '0');
	}
    return(count);
}