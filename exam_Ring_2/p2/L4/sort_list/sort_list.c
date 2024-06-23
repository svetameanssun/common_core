/*Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}*/

#include "list.h"
static int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swap;
    t_list * tmp;

    tmp = lst;
    while(tmp->next != NULL)
    {
        if ((*cmp)(tmp->data, tmp->next->data) == 0)
        {
            swap = tmp->data;
            tmp->data = tmp->next->data;
            tmp->next->data = swap;
            tmp = lst;
        }
        else
            tmp = tmp->next;
    }
    tmp = lst;
    return(tmp);
}

int main()
{
    int a = 222;
    int b = 31;
    int c = 22;
    int d = 2;
    int e = 1;

    t_list node1;
    t_list node2;
    t_list node3;
    t_list node4;
    t_list node5;
    t_list *RES;

    node1.data = a;
    node1.next = &node2;
    node2.data = b;
    node2.next = &node3;
    node3.data = c;
    node3.next = &node4;
    node4.data = d;
    node4.next = &node5;
    node5.data = e;
    node5.next = NULL;
    RES = &node1;
    while(RES)
    {
        printf("%d\n", RES->data);
        RES = RES->next;
    }
    printf("Sorted:\n");
    RES = sort_list(&node1, ascending);
    while(RES)
    {
        printf("%d\n", RES->data);
        RES = RES->next;
    }
}   

