/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:59:53 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 13:21:00 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*move_node;
	t_list	*res_node;

	if (!lst)
		return (NULL);
	move_node = malloc(sizeof(t_list));
	res_node = move_node;
	while (lst->next != NULL)
	{
		move_node->content = f(lst->content);
		move_node->next = malloc(sizeof(t_list));
		if (move_node->next == NULL)
		{
			ft_lstclear(&res_node, del);
			return (NULL);
		}
		move_node = move_node->next;
		lst = lst->next;
	}
	move_node->content = f(lst->content);
	move_node->next = NULL;
	return (res_node);
}
