#include "push_swap.h"


void	while_ra(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
	while (temp->cost_a > 0)
	{
		rotate(stck_a, 'a');
        temp->cost_a--;
	}
	push(stck_b, stck_a, 'a');
}

void	while_rb(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
	while (temp->cost_b > 0)
	{
		rotate(stck_b, 'b');
        temp->cost_b--;
	}
	push(stck_b, stck_a, 'a');
}


void	while_rra(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
    while (temp->cost_a < 0)
	{
		reverse_rotate(stck_a, 'a');
        temp->cost_a++;
	}
	push(stck_b, stck_a, 'a');
}

void	while_rrb(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
	while (temp->cost_b < 0)
	{
		reverse_rotate(stck_b, 'b');
		temp->cost_b++;
	}
	push(stck_b, stck_a, 'a');
}

void	while_rr(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
	while (temp->cost_a > 0 && temp->cost_b > 0)
	{
		double_rotate(stck_a, stck_b);
		temp->cost_a--;
		temp->cost_b--;
	}
	if (temp->cost_a == 0 && temp->cost_b != 0)
		rotate(stck_b, 'b');
	else
		rotate(stck_a, 'a');
}

void	while_rrr(t_stack **stck_a, t_stack **stck_b, t_stack *temp)
{
	while (temp->cost_a < 0 && temp->cost_b < 0)
	{
		double_reverse_rotate(stck_a, stck_b);
		temp->cost_a++;
		temp->cost_b++;
	}
	if (temp->cost_a == 0 && temp->cost_b != 0)
		reverse_rotate(stck_b, 'b');
	else
		reverse_rotate(stck_a, 'a');
}

void	while_rra_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_a < 0)
	{
		reverse_rotate(stack_a,'a');
		temp->cost_a++;
	}
	while_rb(stack_a, stack_b, temp);
}

void	while_rrb_2(t_stack **stack_a, t_stack **stack_b, t_stack *temp)
{
	while (temp->cost_b < 0)
	{
		reverse_rotate(stack_b, 'b');
		temp->cost_b++;
	}
	while_ra(stack_a, stack_b, temp);
}