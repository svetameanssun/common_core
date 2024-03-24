#include "push_swap.h"

void print_stack_contents(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%ld\n", stck->content);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}

void print_stack_positions(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%d\n", stck->position);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}
void print_stack_targets(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%d\n", stck->target);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}

void print_stack_cost_b(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%d\n", stck->cost_b);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}

void print_stack_cost_a(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%d\n", stck->cost_a);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}
void print_stack_cost(t_stack * stck)
{
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%d\n", stck->cost);
        stck = stck->next;
    }
    printf("---------------------------------------------------\n");
}

void print_node_content(t_stack * stck)
{
    printf("%ld\n", stck->content);
}

/*int main()
{
    t_stack *node0 = malloc(sizeof(t_stack));
    t_stack *node1 = malloc(sizeof(t_stack));
    t_stack *node2 = malloc(sizeof(t_stack));

    node0->content = 1000000;
    node0->target = 2;
    node0->position = 0;
    node0->cost_a = 1;
    node0->cost_b = -1;
    node0->next = node1;

    node1->content = -22222222;
    node1->target = 0;
    node1->position = 1;
    node1->cost_a = 0;
    node1->cost_b = 0;
    node1->next = node2;

    node2->content = 0;
    node2->target = 1;
    node2->position = 2;
    node2->cost_a = 1;
    node2->cost_b = 0;
    node2->next = NULL;

    print_stack_contents(node0);
    print_node_content(node0);

    t_stack * max_node;
    t_stack * min_node;
    max_node = find_largest_cont(node0);
    min_node = find_smallest_cont(node0);
    print_node_content(max_node);
    print_node_content(min_node);
    print_stack_contents(min_node);
    printf("%d",min_node->position);
}*/