# include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    t_list *save = begin_list;
    int count = 0;
    while(save)
    {
        count++;
        save = save->next;
    }
    return(count);
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