/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:38:58 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/13 15:24:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ')
	{
		i++;
	}
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = sign * -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res + nptr[i] - 48) * 10;
		i++;
	}
	return (res / 10 * sign);
}

int	main(void)
{
	// Write C code here
	// char *hw = "         +23h3";
	// printf("%d", atoi(hw));
	// ft_strtonbr("123");
	printf("%d", ft_atoi("   -2147483648"));
	return (0);
}