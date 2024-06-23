#include "ft_list.h"
#include <stdio.h>

/*int ft_list_size(t_list *begin_list)
{
    int i = 1;
    while(begin_list->next)
    {
        i++;
        begin_list = begin_list->next;
    }
    return(i);
}*/

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

int main()
{ 
    char name[10] = "Svetlana";
    char p_name[11] = "Leonidovna";
    char l_name[11] = "Titovskaia";
    
    t_list node1;
    t_list node2;
    t_list node3;

    node1.data = name;
    node2.data = p_name;
    node3.data = l_name;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;
    printf("%i",ft_list_size(&node1));
    
}