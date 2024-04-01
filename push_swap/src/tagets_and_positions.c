/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tagets_and_positions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:01:32 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:01:40 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack **stck)
{
	int		pos;
	t_stack	*start_stck;
	t_stack	*temp_stck;

	pos = 0;
	start_stck = *stck;
	temp_stck = *stck;
	while (temp_stck)
	{
		(temp_stck->position = pos);
		temp_stck = temp_stck->next;
		pos++;
	}
	stck = &start_stck;
}

void	set_targets(t_stack **stck_a, t_stack **stck_b, long larger)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*save_a;
	t_stack	*save_b;

	a = *stck_a;
	b = *stck_b;
	save_a = a;
	save_b = b;
	while (b)
	{
		while (a)
		{
			if (a->content < larger && a->content > b->content)
			{
				b->target = a->position;
				larger = a->content;
			}
			a = a->next;
		}
		larger = 2147483647;
		a = *stck_a;
		b = b->next;
	}
	stck_b = &save_b;
}
