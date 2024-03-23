#include "push_swap.h"

t_stack *create_node()
{
    t_stack *stck;

    stck = malloc(sizeof(t_stack));
    if(!stck)
        return(0);
    stck->content = 0;
    stck->target = 0;
    stck->position = 0;
    stck->cost_a = 0;
    stck->cost_b = 0;
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
    while(stack_size(* a)> 3)
    {
        push(a, b, 'b');
    }
}

void remove_last_node(t_stack ** stck)
{
    t_stack * start_stck;
    t_stack * temp;

    temp = *stck;
    start_stck = *stck;
    while(temp->next->next)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    stck = &start_stck;
}



