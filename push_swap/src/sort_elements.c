/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:21:51 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 16:40:03 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_alg(t_stack **stck_a, t_stack **stck_b, t_stack *cheapest)
{
	if (!stck_a || !stck_b || !cheapest)
		ft_error();
	if (cheapest->cost_a == 0 && cheapest->cost_b == 0)
		push(stck_b, stck_a, 'a');
	else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		double_reverse_rotate(stck_a, stck_b);
	else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		double_rotate(stck_a, stck_b);
	else if (cheapest->cost_a < 0)
		reverse_rotate(stck_a, 'a');
	else if (cheapest->cost_a > 0)
		rotate(stck_a, 'a');
	else if (cheapest->cost_b < 0)
		reverse_rotate(stck_b, 'b');
	else if (cheapest->cost_b > 0)
		rotate(stck_b, 'b');
}

void	sort_three_elements(t_stack **stck)
{
	int	min_node_pos;
	int	max_node_pos;

	if (!*stck)
		ft_error();
	min_node_pos = find_smallest_cont_pos(stck);
	max_node_pos = find_largest_cont_pos(stck);
	if (min_node_pos == 0 && max_node_pos == 2)
		return ;
	else if (min_node_pos == 0 && max_node_pos == 1)
		sort_case_one(stck);
	else if (min_node_pos == 2 && max_node_pos == 1)
		sort_case_two(stck);
	else if (min_node_pos == 1 && max_node_pos == 2)
		sort_case_three(stck);
	else if (min_node_pos == 1 && max_node_pos == 0)
		sort_case_four(stck);
	else if (min_node_pos == 2 && max_node_pos == 0)
		sort_case_five(stck);
}

int	min_node_is_superior(t_stack **stck_a)
{
	int	min_node_pos;

	min_node_pos = find_smallest_cont_pos(stck_a);
	if (min_node_pos >= stack_size(stck_a) / 2)
		return (1);
	else if (min_node_pos < stack_size(stck_a) / 2)
		return (2);
	return (0);
}
