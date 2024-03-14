#include "best_node.h"
#include <stdio.h>
#include <stdlib.h>

int ft_list_size(bn *lst)
{
    int count = 0;
    while(lst)
    {
        count++;
        lst = lst->next_n;
    }
    return(count);
}

void	ft_lst_add_front(bn **lst, bn *new)
{
    if(lst && new)
    {
        new->next_n = *lst;
        *lst = new; 
    }
}

void ft_put_str_node(bn *node)
{
    while(node)
    {
        printf("%s ", node->content);
        node = node->next_n;
    }
}



int main()
{ 
    char name[10] = "Svetlana";
    char p_name[11] = "Leonidovna";
    char l_name[11] = "Titovskaia";
    char title[18] = "The Nicest Person";
    
    bn * node1 = malloc(sizeof(bn));
    bn *node2 = malloc(sizeof(bn));
    bn * node3 = malloc(sizeof(bn));
    bn * node4 = malloc(sizeof(bn));

    node1->content = name;
    node2->content = p_name;
    node3->content = l_name;
    node4->content = title;

    node1->next_n = node2;
    node2->next_n = node3;
    node3->next_n = NULL;

    printf("%i\n",ft_list_size(node1));
    ft_lst_add_front(&node1, node4);
    ft_put_str_node(node1);

}