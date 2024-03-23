#include "push_swap.h"

long * words_to_arr(int argc, char **argv)
{
	int index;
    int arr_len;
    long *arr;

    index = 0;
    arr_len = argc -1;
    arr = (long*)malloc(arr_len * sizeof(long));
    if(!arr || argc <= 2 || !argv)
    {
        printf("este1");
        return(0);
    }
    while(index < arr_len)
    {
        if (!input_valid_word(argv[1 + index]))
        {
            printf("este2");
            free(arr);
            return(0);
        }
        arr[index] = atol(argv[1 + index]);
        index++;
    }
    if (!longs_unique(arr,arr_len))
    {
        printf("este3");
        free(arr);
        return(0);
    }
	return(arr);
}

t_stack	*words_to_stack(int argc, char **argv)
{
    long *arr;
    int arr_len;
    t_stack *stck;

    arr_len = argc -1;
    arr = words_to_arr(argc, argv);
    if(argc <= 2 || !argv || !arr)
    {
        return(0);
    }
    stck = array_to_stack(arr,arr_len);
    return(stck);
}
