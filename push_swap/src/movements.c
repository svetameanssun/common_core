#include "push_swap.h"

void swap(t_stack **stck, char stck_name)
{
    t_stack *temp;
    t_stack *temp2;
    
    if (((*stck)->next == NULL) || (*stck == NULL) )
        return;
    // maybe there will be some some operationes done without printing the result??
    temp = *stck;
    temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = temp;
    *stck = temp2;

    if(stck_name ==  'a')
        write(1, "sa\n", 3);
    else if (stck_name == 'b')
        write(1, "sb\n", 3);
}


void double_swap(t_stack ** a, t_stack **b)
{
    swap(a, 'a');
    swap(b, 'b');
}

void push(t_stack **src, t_stack **dest, char dest_name)
{
    if(!src)
        return;
    t_stack *temp;
    t_stack *temp2;

    temp = *src;
    temp2 = temp->next;
    temp->next = *dest;
    *dest = temp;
    *src = temp2;
    if (dest_name == 'a')
        write(1, "pa\n", 3);
    else if (dest_name == 'b')
        write(1, "pb\n", 3);
}
// ROTATE - and - REVERSE_ROTATE return void or s_stack * ???
void rotate(t_stack **stck, char stck_name)
{
    if(*stck == NULL || (*stck)->next == NULL)
        return;
    t_stack *temp;
    t_stack *temp2;

    temp = *stck;
    temp2 = temp;

    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
    *stck = (*stck)->next;
    temp->next = NULL;

    if (stck_name == 'a')
        write(1, "ra\n", 3);
    else if (stck_name == 'b')
        write(1, "rb\n", 3);
}
void double_rotate(t_stack **a, t_stack **b)
{
    rotate(a, 'a');
    rotate(b, 'b');
}

void reverse_rotate(t_stack **stck, char stck_name)
{
    if ((*stck) == NULL || (*stck)->next == NULL)
        return;
    t_stack *temp;
    t_stack *last;

    temp = *stck;
    while(temp && temp->next && temp->next->next)
    {
        temp = temp->next;
    }
    last = temp->next;
    last->next = *stck;
    temp->next = NULL;
    *stck = last;
    last = NULL;
    temp = NULL;

    if (stck_name == 'a')
        write(1, "rra\n", 4);
    else if (stck_name == 'b')
        write(1, "rrb\n", 4);
}


void double_reverse_rotate(t_stack **a, t_stack **b)
{
    reverse_rotate(a, 'a');
    reverse_rotate(b, 'b');
}

/*int main()
{
    int i = 1;
    int j = 121;
    t_stack *lst= (t_stack *)malloc(sizeof(t_stack)); // IMPORTANTE!
    t_stack *lst2 = (t_stack *)malloc(sizeof(t_stack));

    t_stack *aux;// = (t_stack *)malloc(sizeof(t_stack));
    t_stack *aux2;
    aux = lst;
    aux2 = lst2;
    while(i < 11)
    {
        
        lst->content = (long)i;
        lst2->content = (long)j;
        
        lst->next= malloc(sizeof(t_stack));
        lst2->next= malloc(sizeof(t_stack));

        lst = lst->next;
        lst2 = lst2->next;

        i++;
        j+=44;
    }
    
    printf("original stacks: \n");
    print_stack_contents(aux);
    print_stack_contents(aux2);
    push(&aux2, &aux, 'a');
    print_stack_contents(aux);
    print_stack_contents(aux2);
}*/
