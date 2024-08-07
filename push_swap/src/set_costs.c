/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:21:54 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:21:55 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_stack **stck, int index)
{
	int	cost;
	int	size_stck;

	if (!*stck)
		ft_error();
	cost = 0;
	size_stck = stack_size(stck);
	if (index > size_stck / 2)
		cost = (size_stck - index) * -1;
	else
		cost = index;
	return (cost);
}

void	set_costs(t_stack **stck_a, t_stack **stck_b)
{
	t_stack	*b;
	t_stack	*save_b;

	if (!*stck_a || !*stck_b)
		ft_error();
	b = *stck_b;
	save_b = b;
	while (b)
	{
		b->cost_a = calc_cost(stck_a, b->target);
		b->cost_b = calc_cost(stck_b, b->position);
		b->cost = ft_abs(b->cost_a) + ft_abs(b->cost_b);
		b = b->next;
	}
	stck_b = &save_b;
}

t_stack	*find_lowest_cost(t_stack **b)
{
	int		lowest;
	t_stack	*temp_b;
	t_stack	*lowest_cost_node;

	if (!*b)
		ft_error();
	lowest = 2147483647;
	temp_b = *b;
	lowest_cost_node = NULL;
	while (temp_b)
	{
		if (temp_b->cost < lowest)
		{
			lowest_cost_node = temp_b;
			lowest = temp_b->cost;
		}
		temp_b = temp_b->next;
	}
	return (lowest_cost_node);
}
