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
	printf("Sorted A\n");
	print_stack_contents(a);
	printf("B\n");
	print_stack_contents(b);
	
	//SET targets
	set_targets(&a, &b);
	//PRINT TARGETS B:
	printf("TARGETS_B:\n");
	print_stack_targets(b);

	//SET costs
	set_cost(&b);

	//PRINT POSITIONS B:
	printf("POSITIONS_B:\n");
	print_stack_positions(b);


	//PRINT COSTS A:
	printf("COSTS_A:\n");
	print_stack_cost_a(b);

	//PRINT COSTS B:
	printf("COSTS_B:\n");
	print_stack_cost_b(b);

	//PRINT COSTS:
	printf("COSTS:\n");
	print_stack_cost(b);

	//FIND THE LOWEST COST:
	t_stack *lowest_cost = find_lowest_cost(&b);

	//PRINT THE LOWEST COST:
	printf("PRINT THE LOWEST COST %d\n", lowest_cost->cost);

	//PRINT THE MEAN OF A:
	printf("PRINT THE MEAN OF A %d\n",stack_contents_mean(&a));
	



    free_stack(&a);
    free_stack(&b);
    return(1);
}
