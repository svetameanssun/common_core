/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:34 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 14:16:01 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

long	ft_atol(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while(*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = sign * (-1);
		str++;
	}
	if (*str == '+')
		str++;
	while (*str && *str != ' ')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

long	stack_contents_mean(t_stack **stck)
{
	long	divident;
	int		divisor;
	t_stack	*temp_stck;

	if (!stck)
		ft_error();
	divident = 0;
	divisor = 1;
	temp_stck = *stck;
	while (temp_stck)
	{
		divident += temp_stck->content;
		divisor++;
		temp_stck = temp_stck->next;
	}
	divisor--;
	return (divident / divisor);
}

/*int main()
{
	printf("%ld", atol("   12212126   1232  "));
}*/
