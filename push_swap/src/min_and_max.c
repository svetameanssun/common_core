#include "push_swap.h"

t_stack *find_largest_cont(t_stack * stck)
{
    t_stack *max_content = malloc(sizeof(t_stack));
    max_content->content = -2147483648;
    while(stck)
    {
        if(max_content->content < stck->content)
            max_content = stck;
        stck = stck->next;
    }
    return(max_content);
}

t_stack *find_smallest_cont(t_stack * stck)
{
    t_stack *min_content = malloc(sizeof(t_stack));
    min_content->content = 2147483647;
    while(stck)
    {
        if(min_content->content > stck->content)
            min_content = stck;
        stck = stck->next;
    }
    return(min_content);
}