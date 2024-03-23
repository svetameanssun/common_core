#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack * a = create_a(argc, argv);
    t_stack * b = NULL;
    
    push_to_b(&a, &b);
	print_stack_contents(a);
	order_three_elements(&a);
	print_stack_contents(a);
	printf("\n");
	print_stack_contents(b);
    

    free_stack(&a);
    free_stack(&b);
    return(1);
}
