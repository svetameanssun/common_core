#include "push_swap.h"

t_stack *create_node()
{
    t_stack *stck;

    stck = malloc(sizeof(t_stack));
    if(!stck)
        ft_error();
    stck->content = 0;
    stck->position = 0;
    stck->target = 0;
    stck->cost_a = 0;
    stck->cost_b = 0;
    stck->cost = 0;
    stck->next = NULL;
    return(stck);
    
}

t_stack *create_a(int argc, char **argv)
{
    t_stack * a;

    if(!argc || argc < 1)
        ft_error();
    a = args_to_stack(argc, argv);
    return(a);
}

int first_is_smallest(t_stack **stck)
{
    int smallest_cont_pos;
    if(!stck)
        ft_error();
    smallest_cont_pos = find_smallest_cont_pos(stck);
    if(smallest_cont_pos == 0)
    {
        return(smallest_cont_pos);
    }
    return(smallest_cont_pos);
}

//this function sends nodes from a to b till the size of a is 3 nodes






