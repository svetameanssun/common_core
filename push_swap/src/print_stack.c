/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:19 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/29 15:22:20 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack_contents(t_stack * stck)
{
    
    printf("-------------------------------------------------:\n");
    printf("%5s %5s %5s %7s %7s %5s\n", "| cont |", "| pos |", "| targ |", "| cost_a |", "| cost_b |", "| cost |");
    printf("-------------------------------------------------:\n");
    while(stck)
    {
        printf("%7ld %7d %7d %9d %9d %7d\n", stck->content, stck->position, stck->target, stck->cost_a, stck->cost_b, stck->cost);
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