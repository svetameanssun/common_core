/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:23:00 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:23:01 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_stack(t_stack **stck)
{
	t_stack	*aux;
	t_stack	*temp;
	int		size;

	aux = *stck;
	size = stack_size(stck);
	while (size > 0)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
		size--;
	}
	stck = NULL;
}

/*void	*free_all(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}*/

int	is_sorted(t_stack **stck)
{
	t_stack *temp;

	temp = *stck;
	if (!temp)
		return (1);
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}