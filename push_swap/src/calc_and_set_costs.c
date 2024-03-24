#include "push_swap.h"

int calc_cost(t_stack **b, int index)
{
    int cost;
    int size_b;

    cost = 0;
    size_b = stack_size(b);
    if(index > size_b/2)
        cost = (size_b - index) * -1;
    else
        cost = index;
    return(cost);
}

void set_cost(t_stack **b)
{
    t_stack * temp_b;
    t_stack *save_temp_b;
    
    temp_b = *b;
    save_temp_b = temp_b;
    while(temp_b)
    {
        temp_b->cost_a = calc_cost(b, temp_b->target);
        temp_b->cost_b = calc_cost(b, temp_b->position);
        temp_b->cost = ft_abs(temp_b->cost_a) + ft_abs(temp_b->cost_a);
        temp_b = temp_b->next;
    }
    b = &save_temp_b;
}

t_stack *find_lowest_cost(t_stack **b)
{
    int lowest;
    t_stack * temp_b;
    t_stack *lowest_cost_node;
    
    lowest = 2147483647;
    temp_b = *b;
    lowest_cost_node = NULL;
    while(temp_b)
    {
        if(temp_b->cost < lowest)
        {
            lowest_cost_node = temp_b;
            lowest = temp_b->cost;
        }
        temp_b = temp_b->next;
    }
    return(lowest_cost_node);
}


