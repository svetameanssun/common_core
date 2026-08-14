/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:21:20 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 16:14:10 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stck, char stck_name)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (((*stck)->next == NULL) || (*stck == NULL))
		ft_error();
	temp = *stck;
	temp2 = temp->next;
	temp->next = temp2->next;
	temp2->next = temp;
	*stck = temp2;
	set_positions(stck);
	if (stck_name == 'a')
		write(1, "sa\n", 3);
	else if (stck_name == 'b')
		write(1, "sb\n", 3);
}

void	push(t_stack **src, t_stack **dest, char dest_name)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!src)
		ft_error();
	temp = *src;
	temp2 = temp->next;
	temp->next = *dest;
	*dest = temp;
	*src = temp2;
	set_positions(src);
	set_positions(dest);
	if (dest_name == 'a')
		write(1, "pa\n", 3);
	else if (dest_name == 'b')
		write(1, "pb\n", 3);
}

void	rotate(t_stack **stck, char stck_name)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (*stck == NULL || (*stck)->next == NULL)
		ft_error();
	temp = *stck;
	temp2 = temp;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = temp;
	*stck = (*stck)->next;
	temp->next = NULL;
	set_positions(stck);
	if (stck_name == 'a')
		write(1, "ra\n", 3);
	else if (stck_name == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stck, char stck_name)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stck) == NULL || (*stck)->next == NULL)
		ft_error();
	temp = *stck;
	while (temp && temp->next && temp->next->next)
		temp = temp->next;
	last = temp->next;
	last->next = *stck;
	temp->next = NULL;
	*stck = last;
	last = NULL;
	temp = NULL;
	set_positions(stck);
	if (stck_name == 'a')
		write(1, "rra\n", 4);
	else if (stck_name == 'b')
		write(1, "rrb\n", 4);
}
