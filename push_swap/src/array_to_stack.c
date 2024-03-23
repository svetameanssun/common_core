#include "push_swap.h"

t_stack *array_to_stack(long *array, int array_len)
{
    int index;
    t_stack *stck;
    t_stack * stck_start;
    
    index = 0;
    stck = create_node();
    stck->content = array[index++];
    stck_start = stck;
    stck->next = create_node();
    while(index < array_len)
    {
        stck = stck->next;
        stck->content = array[index];
        stck->position = index;
        index++;
        if(index >= array_len)
            break;
        stck->next = create_node();
    }
    return(stck_start);
}

t_stack	*args_to_stack(int argc, char **argv)
{
	int word_cnt;
	char *str;
	t_stack *stck;

    word_cnt = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		str = argv[1];
		word_cnt = word_count(str);
		stck = str_to_stack(str, word_cnt);
		if (!stck)
        {
			ft_error();
            
        }
        //print_stack_contents(stck);
	}
	else if (argc > 2)
	{
		stck = words_to_stack(argc, argv);
		if (!stck)
        {
            printf("error2");
			ft_error(); 
        }//print_stack_contents(stck);
	}
	return(stck);
}

