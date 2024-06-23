#include "best_node.h"
#include <stdio.h>
#include <stdlib.h>

int ft_list_size(struct best_node *lst)
{
    int count = 0;
    while(lst)
    {
        count++;
        lst = lst->next_n;
    }
    return(count);
}
bn *ft_lstnew(char *content)
{
    bn * new_node;

    new_node = malloc(sizeof(bn));
    if (new_node == NULL)
		return (NULL);
    new_node->content = content;
    new_node->next_n = NULL;
    return(new_node);
    
}

void	ft_lst_add_front(bn **lst, bn *new)
{
    new->next_n = *lst;
    *lst = new;
}
bn *ft_lstlast(bn *lst)
{
    while(lst->next_n)
    {
        lst = lst->next_n;
    }
    return(lst);
}
void ft_lstadd_back(bn **lst, bn *new)
{
    bn *aux;
    if(!(*lst))
        *lst = new;
    else
    {
        aux = ft_lstlast(*lst);
        aux->next_n = new;
    }
}

void ft_put_str_node(bn *node)
{
    while(node)
    {
        printf("%s ", node->content);
        node = node->next_n;
    }
    printf("\n");
}
void del(bn * lst)
{
    lst->content = NULL;
    /*lst = lst->next_n;*/
}
void ft_lstdelone(bn *lst, void (*del)(void *))
{
    del((void*)lst);
    free(lst);
}

void ft_lstclear(bn **lst, void (*del)(void *))
{
    bn *aux;
    while((*lst))
    {   
        aux = (*lst)->next_n;
        ft_lstdelone(*lst, del);
        *lst = aux;

    }
}

int main()
{ 
    char name[12] = "|Svetlana|";
    char p_name[13] = "|Leonidovna|";
    char l_name[13] = "|Titovskaia|";
    char title[20] = "|The Nicest Person|";
    
    bn * node1 = malloc(sizeof(bn));
    bn *node2 = malloc(sizeof(bn));
    bn * node3 = malloc(sizeof(bn));
    bn * node4 = malloc(sizeof(bn));
    bn *node5 = ft_lstnew("|Guapa Sexy Hot|");
    bn * node6 = malloc(sizeof(bn));

    node1->content = name;
    node2->content = p_name;
    node3->content = l_name;
    node4->content = title;
    node6-> content = "|JUST BELIEVE ME|";

    node1->next_n = node2;
    node2->next_n = node3;
    node3->next_n = NULL;

    
    
    ft_put_str_node(node1);
    printf("node size: %i\n",ft_list_size(node1));
    printf("-------------------------------------------------------------\n");
    ft_lst_add_front(&node1, node4);
    ft_put_str_node(node1);
    printf("node size: %i\n",ft_list_size(node1));
    printf("-------------------------------------------------------------\n");
    ft_lst_add_front(&node1, node5);
    ft_put_str_node(node1);
    printf("node size: %i\n",ft_list_size(node1));
    printf("-------------------------------------------------------------\n");
    printf("The last node:\n");
    ft_put_str_node(ft_lstlast(node1));
    printf("-------------------------------------------------------------\n");
    ft_lstadd_back(&node1, node6);
    ft_put_str_node(node1);
    ft_lstdelone(node5->next_n->next_n, del);
    ft_put_str_node(node1);
}