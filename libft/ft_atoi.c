/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:38:58 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/21 16:22:26 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]) != 0)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res *10;
		res = res + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
/*int	main(void)
{
	char *hw = "         +23h3";
	printf("%d", atoi(hw));
	// ft_strtonbr("123");
	printf("%d", ft_atoi(hw));
	return (0);
	//'2' = 50 = 48 + 2 = '0' + 2
}*/