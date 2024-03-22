#include "push_swap.h"

t_stack	*words_to_stack(int argc, char **argv)
{
    int index;
    int arr_len;
    long *arr;
    t_stack *stck;

    index = 0;
    arr_len = argc -1;
    arr = malloc(arr_len * sizeof(long));

	if(argc <= 2 || !argv || !arr)
        return(0);
    while(index < arr_len)
    {
        if (!input_valid(argv[1+index]))
            return(0);
        arr[index] = atol(argv[1+index]);
        index++;
    }
    if (!longs_unique(arr,arr_len))
        return(0);
    stck = stack_from_array(arr,arr_len);
    return(stck);
}
