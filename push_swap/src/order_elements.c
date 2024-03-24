#include "push_swap.h"

void order_three_elements(t_stack **stck)
{
    t_stack *aux;
    t_stack *min_node;
    t_stack *max_node;

    aux = *stck;
    min_node = find_smallest_cont(aux);
    max_node = find_largest_cont(aux);
    if(min_node->position == 0 && max_node->position == 2)
        return;
    else if (min_node->position == 0 && max_node->position == 1)
        order_case_one(stck);
    else if (min_node->position == 2 && max_node->position == 1)
        order_case_two(stck);
    else if (min_node->position == 1 && max_node->position == 2)
        order_case_three(stck);
    else if (min_node->position == 1 && max_node->position == 0)
        order_case_four(stck);
    else if (min_node->position == 2 && max_node->position == 0)
        order_case_five(stck);
    
}

void order_elements(t_stack **a, t_stack **b)
{
    
}


/*int main()
{
    t_stack *node0 = malloc(sizeof(t_stack));
    t_stack *node1 = malloc(sizeof(t_stack));
    t_stack *node2 = malloc(sizeof(t_stack));

    node0->content = 7;
    node0->position = 0;
    node0->target = 2;
    node0->cost_a = 1;
    node0->cost_b = -1;
    node0->next = node1;


    node1->content = 3;
    node1->position = 1;
    node1->target = 0;
    node1->cost_a = 0;
    node1->cost_b = 0;
    node1->next = node2;


    node2->content = 1;
    node2->position = 2;
    node2->target = 1;
    node2->cost_a = 1;
    node2->cost_b = 0;
    node2->next = NULL;

    order_three_elements(&node0);
    print_stack_contents(node0);
}*/