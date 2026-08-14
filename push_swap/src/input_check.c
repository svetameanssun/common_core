/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:48 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 16:54:41 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_not_valid(int c)
{
	return (is_alpha(c) || (c >= 33 && c <= 47) || (c >= 58 && c <= 64)
		|| (c >= 91 && c <= 96) || (c >= 123 && c <= 127) || (c > 0 && c < 32));
}

int	longs_unique(long *arr, int len)
{
	int	i;
	int	j;

	if (!arr)
		return (0);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] > MAX || arr[i] < MIN)
			return (0);
		j = 0;
		while (j < len)
		{
			if (arr[i] == arr[j] && i != j)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	input_valid(char *str, int i)
{
	if (!str[i])
		return (0);
	while (str[i] && str[i + 1])
	{
		if (is_space(str[i]))
			i++;
		if (plus_or_minus(str[i]))
			i++;
		if ((plus_or_minus(str[i - 1]) && is_digit(str[i - 2]))
			|| is_not_valid(str[i]))
			return (0);
		if ((plus_or_minus(str[i - 1])) && is_digit(str[i]) && (i == 1
				|| is_space(str[i - 2])))
			i++;
		if (is_digit(str[i]))
			i++;
		if (plus_or_minus(str[i]) && (plus_or_minus(str[i + 1])
				|| end_or_space(str[i + 1])))
			return (0);
	}
	if ((plus_or_minus(str[0])) && str[1] == '\0')
		return (0);
	i++;
	return (i);
}
