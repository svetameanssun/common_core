/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:21:43 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:35:37 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_one(t_stack **stck)
{
	if (!*stck)
		ft_error();
	swap(stck, 'a');
	rotate(stck, 'a');
	set_positions(stck);
}

void	sort_case_two(t_stack **stck)
{
	if (!*stck)
		ft_error();
	reverse_rotate(stck, 'a');
	set_positions(stck);
}

void	sort_case_three(t_stack **stck)
{
	if (!*stck)
		ft_error();
	swap(stck, 'a');
	set_positions(stck);
}

void	sort_case_four(t_stack **stck)
{
	if (!*stck)
		ft_error();
	rotate(stck, 'a');
	set_positions(stck);
}

void	sort_case_five(t_stack **stck)
{
	if (!*stck)
		ft_error();
	swap(stck, 'a');
	reverse_rotate(stck, 'a');
	set_positions(stck);
}
