#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack * a;
	t_stack * b;

	a = create_a(argc, argv);
    b = NULL;

	
    //PUSH from A to B
	push_to_b(&a, &b);
	//ORDER 3 Elements:
	order_three_elements(&a);
	
	//SET targets
	set_targets(&a, &b);
	printf("Print A and B:\n");
	print_stack_contents(a);
	print_stack_contents(b);
	set_cost(&a, &b);
	print_stack_contents(a);
	print_stack_contents(b);

	print_node_content(find_lowest_cost(&b));
	
    free_stack(&a);
    free_stack(&b);
    return(1);
}
