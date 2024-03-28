#include "push_swap.h"

void push_swap(t_stack ** stck_a, t_stack ** stck_b)
{
	set_positions(stck_a);
	if(!is_sorted(stck_a))
	{
		if(stack_size(stck_a) == 2)
			swap(stck_a, 'a');
		else if (stack_size(stck_a) == 3)
			sort_three_elements(stck_a);
		else
			sort_stacks(stck_a, stck_b, stack_size(stck_a));
	}
}

void    push_smaller(t_stack **stck_a, t_stack **stck_b, long mean)
{
    if ((*stck_a)->content <= mean)
        push(stck_a, stck_b, 'b');
    else
	{
        rotate(stck_a, 'a');
		//printf("CASE1\n");
	}
}

void divide_stacks(t_stack ** stck_a, t_stack **stck_b, int stck_a_size)
{
    if(stck_a_size == 4)
    {
        while(first_is_smallest(stck_a) != 0)
		{
            rotate(stck_a, 'a');
		}
		push(stck_a, stck_b, 'b');
        return;
    }
    while(stck_a_size > 3)
    {
        push_smaller(stck_a, stck_b, stack_contents_mean(stck_a));
        stck_a_size = stack_size(stck_a);
	}
}

void sort_stacks(t_stack **stck_a, t_stack **stck_b, int stck_a_size)
{
	divide_stacks(stck_a, stck_b, stck_a_size);
	sort_three_elements(stck_a);
	//printf("GOT OUT\n");
	
	while(*stck_b)
	{
		set_positions(stck_a);
		set_positions(stck_b);
		set_targets(stck_a, stck_b);
		set_costs(stck_a, stck_b);
		sorting_alg(stck_a, stck_b, find_lowest_cost(stck_b));
		set_positions(stck_a);
		set_positions(stck_b);
		//print_stack_contents(*stck_a);
		//print_stack_contents(*stck_b);
	}
	while(!is_sorted(stck_a))
	{
		reverse_rotate(stck_a, 'a');
		set_positions(stck_a);
	}
}

int main(int argc, char **argv)
{
	t_stack * a;
	t_stack *b;
	
	a = create_a(argc, argv);
	b = NULL;
	
	push_swap(&a, &b);
	//printf("VAR1");
	//print_stack_contents(a);
	//print_stack_contents(b);
	
    free_stack(&a);
    return(1);
}
