#include "push_swap.h"

t_stack *find_largest_cont(t_stack * stck)
{
    t_stack *max_content = malloc(sizeof(t_stack));
    max_content->content = -2147483648;
    while(stck)
    {
        if(max_content->content < stck->content)
            max_content = stck;
        stck = stck->next;
    }
    return(max_content);
}

t_stack *find_smallest_cont(t_stack * stck)
{
    t_stack *min_content = malloc(sizeof(t_stack));
    min_content->content = 2147483647;
    while(stck)
    {
        if(min_content->content > stck->content)
            min_content = stck;
        stck = stck->next;
    }
    return(min_content);
}

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
	t_stack * save;
	

    stck_size = 0;
	temp = *stck;
	save = temp;
    while(temp)
    {
        stck_size++;
        temp = temp->next;
    }
	stck = &save;
    return(stck_size);
}