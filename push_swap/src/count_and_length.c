#include "push_swap.h"

int	word_count(char *str)
{
	int	word_cnt;
	int i;

	word_cnt = 1;
	i = 0;
	while(str[i] && str[i + 1])
	{
		if(str[i] != ' ' && end_or_space(str[i + 1]))
		{
			word_cnt++;
		}
		i++;
	}
	return (word_cnt);
}

int stack_size(t_stack **stck)
{
    int stck_size;
	t_stack * temp;

	temp = *stck;

    stck_size = 0;
    while(temp)
    {
        stck_size++;
        temp = temp->next;
    }
    return(stck_size);
}