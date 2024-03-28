#include "push_swap.h"

void set_positions(t_stack ** stck)
{
    int pos;
    t_stack * start_stck;
    t_stack * temp_stck;

    pos = 0;
    start_stck = *stck;
    temp_stck = *stck;
    while(temp_stck)
    {
        (temp_stck->position = pos);
        temp_stck= temp_stck->next;
        pos++;
    }
    stck = &start_stck;
}

void set_targets(t_stack ** stck_a, t_stack ** stck_b)
{
    t_stack * a;
    t_stack * b;
    t_stack * save_a;
    t_stack * save_b;
    long larger;

    if(!stck_a ||!stck_b)
        ft_error();
    a = *stck_a;
    b = *stck_b;
    save_a = a;
    save_b = b;
    larger = 2147483647;

    while(b)
    {
        while(a)
        {
            if(a->content < larger && a->content > b->content)
            {
                
                b->target = a->position;
                larger = a->content;                                                                                                                                                            
            }
            a = a->next;
        }
        larger = 2147483647;
        a = save_a;
        b = b->next;
    }
    stck_a = &save_a;
    stck_b = &save_b;
}
