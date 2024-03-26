#include "push_swap.h"

void	sorting_alg(t_stack **stck_a, t_stack **stck_b, t_stack *cheapest)
{
    
	if (cheapest->cost_a == 0 && cheapest->cost_b == 0)
        push(stck_b, stck_a, 'a');
    else if (cheapest->cost_a < 0 && cheapest->cost_b < 0)
        double_reverse_rotate(stck_a, stck_b);
    else if (cheapest->cost_a > 0 && cheapest->cost_b > 0)
        double_rotate(stck_a,stck_b);
    else if (cheapest->cost_a < 0)
        reverse_rotate(stck_a, 'a');
    else if (cheapest->cost_a > 0)
        rotate(stck_a, 'a');
	else if (cheapest->cost_b < 0)
        reverse_rotate(stck_b, 'b');
    else if (cheapest->cost_b > 0)
        rotate(stck_b, 'b');
}

