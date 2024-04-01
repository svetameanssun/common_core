/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:54 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:22:57 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(void)
{
	t_stack	*stck;

	stck = malloc(sizeof(t_stack));
	if (!stck)
		ft_error();
	stck->content = 0;
	stck->position = 0;
	stck->target = 0;
	stck->cost_a = 0;
	stck->cost_b = 0;
	stck->cost = 0;
	stck->next = NULL;
	return (stck);
}

t_stack	*create_a(int argc, char **argv)
{
	t_stack	*a;

	if (!argc || argc < 1)
		ft_error();
	a = args_to_stack(argc, argv);
	return (a);
}
