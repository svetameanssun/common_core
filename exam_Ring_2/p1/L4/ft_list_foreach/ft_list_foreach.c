#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>

void    ft_list_foreach(t_list *begin_list, char* (*f)(char *))
{
    /*t_list *list_ptr;*/

    while(begin_list)
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }

}

char *to_upper(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i]>= 'a'&& str[i]<= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return(str);

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

    ft_list_foreach(&node1, to_upper);

    /*printf("%s\n", to_upper(name));*/
    t_list *current = &node1;
    while (current) {
        printf("%s\n", (char *)current->data);
        current = current->next;
    }
    
}