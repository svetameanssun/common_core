#include "best_node.h"

void	ft_lst_add_front(t_list **lst, t_list *new)
{
    if (lst && new)
    {
        new->next = *lst;
        *lst = new;
    }
}