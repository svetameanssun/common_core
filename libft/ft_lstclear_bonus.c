/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:54:53 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/05 18:38:18 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *aux;
    
    while(*lst)
    {
        aux = (*lst)->next;
        ft_lstdelone(*lst, del);
        (*lst) = aux;
    }
    *lst = NULL;
}