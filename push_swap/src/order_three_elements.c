#include "push_swap.h"

/*Here I order the list of three elements.
As far as the only possible number of combination of three numbers is SIX
I just detect one of the six variants (Judging by the position of the largest and the smallest number)
and apply the movements to this list depending on the variant of destribution of its elements
Detailed explanation ex00:
                1 10 100 - in this list node.pos with min node.content equals 0,
                            and node.pos with max node.content - 2;

*/

/*
    Right order:
                1 10 100 -  | min node.cont | node.pos = 0
                            | max node.cont | node.pos = 2
    Others:                        
                1 100 10 -  | min node.cont | node.pos = 0
                            | max node.cont | node.pos = 1

                10 100 1 -  | min node.cont | node.pos = 2
                            | max node.cont | node.pos = 1

                10 1 100 -  | min node.cont | node.pos = 1
                            | max node.cont | node.pos = 2

                100 1 10 -  | min node.cont | node.pos = 1
                            | max node.cont | node.pos = 0

                100 10 1 -  | min node.cont | node.pos = 2
                            | max node.cont | node.pos = 0
*/


void order_case_one(t_stack **stck)
{
    swap(stck, 'a');
    rotate(stck, 'a');
}

void order_case_two(t_stack **stck)
{
    reverse_rotate(stck, 'a');
}

void order_case_three(t_stack **stck)
{
    swap(stck, 'a');
}
void order_case_four(t_stack **stck)
{
    rotate(stck, 'a');
}

void order_case_five(t_stack **stck)
{
    swap(stck, 'a');
    reverse_rotate(stck, 'a');
}

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