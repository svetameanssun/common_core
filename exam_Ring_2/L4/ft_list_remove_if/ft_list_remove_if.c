#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (begin_list == NULL || *begin_list == NULL)
    {
        return;
    }
    t_list *cur = *begin_list;

    if(cmp(cur->data, data_ref) == 0)
    {
        *begin_list = cur->next;
        free(cur);
        ft_list_remove_if(begin_list, data_ref, cmp);
    }
    else
    {
        cur = *begin_list;
        ft_list_remove_if(&cur->next, data_ref,cmp);
    }

}

int main()
{ 
    int a = 97;
    int b = 98;
    int c = 99;

    int ref = 99;
    
    t_list node1;
    t_list node2;
    t_list node3;

    node1.data = a;
    node2.data = b;
    node3.data = c;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;

    
    t_list *current = &node1;
    while (current) {
        printf("%s\n", (char *)current->data);
        current = current->next;
    }
    ft_list_remove_if(&node1, to_upper);
}
