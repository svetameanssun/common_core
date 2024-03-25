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
    set_positions(stck);
}

void order_case_two(t_stack **stck)
{
    reverse_rotate(stck, 'a');
    set_positions(stck);
}

void order_case_three(t_stack **stck)
{
    swap(stck, 'a');
    set_positions(stck);
}
void order_case_four(t_stack **stck)
{
    rotate(stck, 'a');
    set_positions(stck);
}

void order_case_five(t_stack **stck)
{
    swap(stck, 'a');
    reverse_rotate(stck, 'a');
    set_positions(stck);
}
