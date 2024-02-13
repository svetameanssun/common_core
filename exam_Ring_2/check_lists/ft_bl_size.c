#include "best_list.h"
#include <stdio.h>

int ft_list_size(bl *list_start)
{
    int i = 1;
    while(list_start->next_el)
    {
        i++;
        list_start = list_start->next_el;
    }
    return i;
}


int main()
{ 
    char name[10] = "Svetlana";
    char p_name[11] = "Leonidovna";
    char l_name[11] = "Titovskaia";
    
    struct best_list node1;
    struct best_list node2;
    struct best_list node3;

    node1.content = name;
    node2.content = p_name;
    node3.content = l_name;

    node1.next_el = &node2;
    node2.next_el = &node3;
    node3.next_el = NULL;
    printf("%i",ft_list_size(&node1));
    
}