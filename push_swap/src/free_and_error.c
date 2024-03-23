#include "push_swap.h"

int ft_error()
{
	write(1, "error\n", 6);
	exit(0);
}

void	free_stack(t_stack **head)
{
	t_stack	*aux;
	t_stack	*temp;
	int		size;

	aux = *head;
	size = stack_size(*head);
	while (size > 0)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
		size--;
	}
	head = NULL;
}