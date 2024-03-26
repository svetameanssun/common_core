#include "push_swap.h"

/*

void push(t_stack **src, t_stack **dest, char dest_name);
void rotate(t_stack **stck, char stck_name);
void double_rotate(t_stack **a, t_stack **b);
void reverse_rotate(t_stack **stck, char stck_name);
void double_reverse_rotate(t_stack **a, t_stack **b);

*/
//void push(t_stack **src, t_stack **dest, char dest_name);
/*void pa(t_stack **b, t_stack **a)
{
    push(b, a, 'a');
    set_positions(a);
    set_positions(b);
}
//void rotate(t_stack **stck, char stck_name);
void ra(t_stack **a)
{
    rotate(a, 'a');
    set_positions(a);
}
void rb(t_stack **b)
{
    rotate(b, 'b');
    set_positions(b);
}

//void double_rotate(t_stack **a, t_stack **b);
void rr(t_stack **a, t_stack **b)
{
    double_rotate(a,b);
    set_positions(a);
    set_positions(b);
}

//void reverse_rotate(t_stack **stck, char stck_name);//
void rra(t_stack **a)
{
    reverse_rotate(a, 'a');
    set_positions(a);
}
void rrb(t_stack **b)
{
    reverse_rotate(b, 'b');
    set_positions(b);
}

//void double_reverse_rotate(t_stack **a, t_stack **b);
void rrr(t_stack **a, t_stack **b)
{
    double_reverse_rotate(a, b);
    set_positions(a);
    set_positions(b);
}*/
void	order_elements(t_stack **stck_a, t_stack **stck_b)
{
    t_stack * a;
    t_stack * b;

    a = *stck_a;
    b = *stck_b;

	if (b->cost_a == 0 && b->cost_b == 0)
        push(stck_b, stck_a, 'a');
    else if (b->cost_a < 0 && b->cost_b < 0)
        double_reverse_rotate(stck_a, stck_b);
    else if (b->cost_a > 0 && b->cost_b> 0)
        double_rotate(stck_a,stck_b);
    else if (b->cost_a < 0)
        reverse_rotate(stck_a, 'a');
    else if (b->cost_a > 0)
        rotate(stck_a, 'a');
	else if (b->cost_b < 0)
        reverse_rotate(stck_b, 'b');
    else if (b->cost_b > 0)
        rotate(stck_b, 'b');
    set_positions(stck_a);
    set_positions(stck_b);
}

void push_lower_cost(t_stack **stck_a,t_stack **stck_b)
{
    t_stack * a;
    t_stack * b;


    a = *stck_a;
    b = *stck_b;

    while(b)
    {
        
    }
    
    
}