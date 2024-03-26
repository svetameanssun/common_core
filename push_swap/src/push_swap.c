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
	printf("Sorted A:\n");
	print_stack_contents(a);
	
	//SET targets
	set_targets(&a, &b);
	printf("Targets B:\n");
	//print_stack_contents(a);
	print_stack_contents(b);
	/*set_cost(&a, &b);
	print_stack_contents(a);
	print_stack_contents(b);*/

	
    free_stack(&a);
    free_stack(&b);
    return(1);
}
