#include "push_swap.h"

void double_swap(t_stack ** a, t_stack **b)
{
    swap(a, 'a');
    swap(b, 'b');
}

void double_rotate(t_stack **a, t_stack **b)
{
    rotate(a, 'a');
    rotate(b, 'b');
}

void double_reverse_rotate(t_stack **a, t_stack **b)
{
    reverse_rotate(a, 'a');
    reverse_rotate(b, 'b');
}

