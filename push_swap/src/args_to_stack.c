#include "push_swap.h"

t_stack *init_stack()
{
    t_stack *stck;

    stck = malloc(sizeof(t_stack));
    if(!stck)
        return(0);
    stck->content = 0;
    stck->target = 0;
    stck->position = 0;
    stck->cost_a = 0;
    stck->cost_b = 0;
    stck->next = NULL;
    return(stck);
    
}

t_stack *stack_from_array(long *array, int array_len)
{
    int index;
    t_stack *stck;
    t_stack * stck_start;
    
    index = 1;
    stck = init_stack();
    stck->content = array[0];
    stck_start = stck;
    
    while(index < array_len)
    {
        stck->next = init_stack();
        stck = stck->next;
        stck->content = array[index];
        stck->position = index;
        index++;
    }
    return(stck_start);
}

int	args_to_stack(int argc, char **argv)
{
	int word_cnt = 0;
	long *arr;
	char *str;
	t_stack *stck;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = (argv[1]);
		word_cnt = word_count(str);
		stck = str_to_numbers(str, word_cnt);
		if (stck == 0)
			ft_error();
		print_stack_contents(stck);
		
	}
	if (argc > 2)
	{
		stck = words_to_numbers(argc, argv);
		if (stck == 0)
			ft_error();
		print_stack_contents(stck);
	}
	return(1);
}

