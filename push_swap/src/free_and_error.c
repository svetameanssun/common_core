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

void	*free_all(char **str, int cont)
{
	int	i;

	i = 0;
	while (i < cont)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int is_sorted(t_stack **stck)
{
	t_stack *temp;

	temp = *stck;
	if(!temp)
		return(1);
	while(temp->next)
	{
		if(temp->content < temp->next->content)
			temp = temp->next;
		else
			return(0);
	}
	return(1);
}