#include "push_swap.h"

int	word_count(char *str)
{
	int	word_cnt;
	int i;

	word_cnt = 0;
	i = 1;
	while (str[i])
	{
		if (is_digit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			word_cnt++;
		}
		i++;
	}
	return (word_cnt);
}

int stack_size(t_stack *stck)
{
    int stck_size;

    stck_size = 0;
    while(stck)
    {
        stck_size++;
        stck = stck->next;
    }
    return(stck_size);
}