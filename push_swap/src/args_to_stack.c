/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:23:12 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 15:40:03 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*words_to_arr(int argc, char **argv)
{
	int		index;
	int		arr_len;
	long	*arr;

	index = 0;
	arr_len = argc - 1;
	arr = (long *)malloc(arr_len * sizeof(long));
	if (!arr || argc <= 2 || !argv)
		ft_error();
	while (index < arr_len)
	{
		if (input_valid(argv[1 + index]) == 0)
		{
			free(arr);
			ft_error();
		}
		arr[index] = atol(argv[1 + index]);
		index++;
	}
	if (!longs_unique(arr, arr_len))
	{
		free(arr);
		ft_error();
	}
	return (arr);
}

t_stack	*words_to_stack(int argc, char **argv)
{
	long	*arr;
	int		arr_len;
	t_stack	*stck;

	arr_len = argc - 1;
	arr = words_to_arr(argc, argv);
	if (argc <= 2 || !argv || !arr)
	{
		free(arr);
		ft_error();
	}
	stck = array_to_stack(arr, arr_len);
	free(arr);
	return (stck);
}

t_stack	*array_to_stack(long *array, int array_len)
{
	int		index;
	t_stack	*stck;
	t_stack	*stck_start;

	if (!array || array_len < 1)
		ft_error();
	index = 0;
	stck = create_node();
	stck->content = array[index++];
	stck_start = stck;
	stck->next = create_node();
	while (index < array_len)
	{
		stck = stck->next;
		stck->content = array[index];
		stck->position = index;
		index++;
		if (index >= array_len)
			break ;
		stck->next = create_node();
	}
	return (stck_start);
}

t_stack	*str_to_stack(char *str, int word_cnt)
{
	int		i;
	int		j;
	long	*res;
	t_stack	*stck;

	i = 0;
	j = 1;
	res = (long *)malloc(sizeof(long) * (word_cnt));
	if (!res)
		ft_error();
	res[0] = ft_atol(str);
	while (j < word_cnt)
	{
		while(is_space(str[i]))
			i++;
		while (str[i] && !is_space(str[i]))
			i++;
		res[j++] = ft_atol(str + i);
	}
	if (!longs_unique(res, word_cnt))
	{
		free(res);
		ft_error();
	}
	stck = array_to_stack(res, word_cnt);
	return (stck);
}

t_stack	*args_to_stack(int argc, char **argv)
{
	int		word_cnt;
	char	*str;
	t_stack	*stck;

	word_cnt = 0;
	stck = NULL;
	if (!argc || argc < 1)
		ft_error();
	if (argc == 2)
	{
		str = argv[1];
		if (input_valid(str) == 0)	
			ft_error();
		word_cnt = word_count(str);
		stck = str_to_stack(str, word_cnt);
		if (!stck)
			ft_error();
	}
	else if (argc > 2)
	{
		stck = words_to_stack(argc, argv);
		if (!stck)
			ft_error();
	}
	return (stck);
}
