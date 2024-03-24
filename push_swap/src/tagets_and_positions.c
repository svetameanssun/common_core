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

int get_target(t_stack ** a, t_stack **b)
{
    int flg;
    int targ;
    long cont;
    t_stack * temp_a;
    t_stack *temp_b;
    
    flg = 0;
    targ = 0;
    cont = 2147483647;
    temp_a = *a;
    temp_b = *b;
    while(temp_a)
    {
        if(temp_a->content < cont && temp_a->content > temp_b->content)
        {
            cont = temp_a->content;
            targ = temp_a->position;
            flg++;
        }
       temp_a = temp_a->next;        
    }
    if (flg == 0)
        targ = 0;
    printf("TARGET%d\n",targ);
    return(targ);
}

void set_targets(t_stack ** a, t_stack **b)
{
    t_stack * temp_b;
    t_stack *temp_a;
    t_stack *save_temp_b;

    temp_b = *b;
    save_temp_b = temp_b;
    while(temp_b)
    {
        temp_b->target = get_target(a, b);
        temp_b = temp_b->next;
    }
    b = &save_temp_b;

}