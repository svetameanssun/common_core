#include "push_swap.h"

void	sort_three_elements(t_stack **stck)
{
	t_stack	*aux;
	t_stack	*min_node;
	t_stack	*max_node;

	aux = *stck;
	min_node = find_smallest_cont(aux);
	max_node = find_largest_cont(aux);
	if (min_node->position == 0 && max_node->position == 2)
		return;
	else if (min_node->position == 0 && max_node->position == 1)
		sort_case_one(stck);
	else if (min_node->position == 2 && max_node->position == 1)
		sort_case_two(stck);
	else if (min_node->position == 1 && max_node->position == 2)
		sort_case_three(stck);
	else if (min_node->position == 1 && max_node->position == 0)
		sort_case_four(stck);
	else if (min_node->position == 2 && max_node->position == 0)
		sort_case_five(stck);
}



/*int main()
{
	t_stack *node0 = create_node();
	t_stack *node1 = create_node();
	t_stack *node2 = create_node();
    t_stack *node3 = create_node();
	t_stack *node4 = create_node();
	t_stack *node5 = create_node();

    node0->content = 10;
    node1->content = 10;
    node2->content = 10;
    node3->content = 10;
    node4->content = 10;
    node5->content = 10;

	

	sort_three_elements(&node0);
	print_stack_contents(node0);
}*/