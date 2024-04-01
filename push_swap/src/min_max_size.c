/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:40 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 15:37:40 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int find_largest_cont_pos(t_stack ** stck_stck)
{
	t_stack	*stck;
	t_stack	*max_content;
	long	max_content;
	int		max_content_pos;
	t_stack	*stck;

	stck = *stck_stck;
	max_content = malloc(sizeof(t_stack));
	if(!max_content)
		return(NULL);
	max_content->content = -2147483648;
	if(!stck)
		return(NULL);
	while(stck)
	{
		if(max_content->content < stck->content)
			max_content = stck;
		stck = stck->next;
	}
	return(max_content);
}*/
int	find_largest_cont_pos(t_stack **stck_stck)
{
    t_stack *stck;
    long    max_content;
    int max_content_pos;

	if (!stck_stck)
		ft_error();
	stck = *stck_stck;
	max_content = -2147483648;
	max_content_pos = stck->position;
	while (stck)
	{
		if (max_content < stck->content)
		{
			max_content_pos = stck->position;
			max_content = stck->content;
		}
		stck = stck->next;
	}
	return (max_content_pos);
}

int	find_smallest_cont_pos(t_stack **stck_stck)
{
	long	min_content;
	int		min_content_pos;
	t_stack	*stck;

	if (!stck_stck)
		ft_error();
	stck = *stck_stck;
	min_content = 2147483647;
	min_content_pos = stck->position;
	while (stck)
	{
		if (min_content > stck->content)
		{
			min_content_pos = stck->position;
			min_content = stck->content;
		}
		stck = stck->next;
	}
	return (min_content_pos);
}

int	word_count(char *str)
{
	int	word_cnt;
	int	i;

	if (!str)
		ft_error();
	word_cnt = 0;
	i = 0;
	while (str[i])
	{
		if(is_space(str[i]))
			i++;
		if (plus_or_minus(str[i]) && (is_space(str[i - 1]) || i== 0))
			word_cnt++;
		if (is_digit(str[i]) && (is_space(str[i - 1]) || i== 0))
			word_cnt++;
		
		i++;
	}
	return (word_cnt);
}

int	stack_size(t_stack **stck)
{
	int		stck_size;
	t_stack	*temp;
	t_stack	*save;

	if (!stck)
		ft_error();
	stck_size = 0;
	temp = *stck;
	save = temp;
	while (temp)
	{
		stck_size++;
		temp = temp->next;
	}
	stck = &save;
	return (stck_size);
}

int	first_is_smallest(t_stack **stck)
{
	int smallest_cont_pos;
	if (!stck)
		ft_error();
	smallest_cont_pos = find_smallest_cont_pos(stck);
	if (smallest_cont_pos == 0)
	{
		return (smallest_cont_pos);
	}
	return (smallest_cont_pos);
}