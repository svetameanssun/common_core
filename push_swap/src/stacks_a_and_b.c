#include "push_swap.h"

t_stack *create_node()
{
    t_stack *stck;

    stck = malloc(sizeof(t_stack));
    if(!stck)
        return(0);
    stck->content = 0;
    stck->position = 0;
    stck->target = 0;
    stck->cost_a = 0;
    stck->cost_b = 0;
    stck->cost = ft_abs(stck->cost_a) + ft_abs(stck->cost_b);
    stck->next = NULL;
    return(stck);
    
}

t_stack *create_a(int argc, char **argv)
{
    t_stack * a;

    a = args_to_stack(argc, argv);
    return(a);
}

//this function sends nodes from a to b till the size of a is 3 nodes
void push_to_b(t_stack ** a, t_stack **b)
{
    int stck_size;

    stck_size = stack_size(a);
    while(stck_size > 3)
    {
        push(a, b, 'b');
        stck_size = stack_size(a);
    }
    set_positions(a);
    set_positions(b);
}





