/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:30:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/23 21:42:06 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*str_to_stack(char *str, int word_cnt)
{
	int	i;
	int	j;
	long	*res;
	t_stack *stck;

	i = 0;
	j = 1;
	res = (long *)malloc(sizeof(long) * (word_cnt));
	if (!res)
		return (0);
	res[0] = ft_atol(str);
	while (j < word_cnt)
	{
		while (str[i] && str[i] != ' ')
			i++;
		i++;
		res[j++] = ft_atol(str + i);
	}
	if (!input_valid_str(str) || !longs_unique(res, word_cnt))
	{
		free(res);
		ft_error();

	}
	stck = array_to_stack(res, word_cnt);
	return (stck);
}
