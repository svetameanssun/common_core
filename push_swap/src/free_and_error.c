#include "push_swap.h"

int ft_error()
{
	write(1, "error\n", 6);
	exit(0);
}

void	free_stack(t_stack **stck)
{
	t_stack	*aux;
	t_stack	*temp;
	int		size;

	aux = *stck;
	size = stack_size(stck);
	while (size > 0)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
		size--;
	}
	stck = NULL;
}