/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:30:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/22 22:53:35 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*str_to_stack(char *str, int word_cnt)
{
	int	i;
	int	j;
	long	*res;
	t_stack *stck;

	i = 0;
	j = 1;
	res = (long *)malloc(sizeof(long) * (word_cnt));
	if (res == 0)
		return (0);
	res[0] = ft_atol(str);
	while (j < word_cnt)
	{
		while (str[i] && str[i] != ' ')
			i++;
		i++;
		res[j] = ft_atol(str + i);
		j++;
	}
	if (!input_valid(str) || !longs_unique(res, word_cnt))
		ft_error();
	stck = stack_from_array(res, word_cnt);
	return (stck);
}

/*int	united_str_size(int arg_num, char **arguments)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	if (arg_num == 1)
		return(0);
	while (i < arg_num)
	{
		j = 0;
		while (arguments[i][j])
		{
			j++;
			count++;
		}
		i++;
	}
	count = count + arg_num - 2;
	return (count);
}*/

/*char	*words_to_str(int argc, char **argv)
{
	int		i;
	int		j;
	int		res_size;
	char	*res;
	int		k;

	i = 1;
	j = 0;
	if (argc == 1)
		return(0);
	res_size = united_str_size(argc, argv);
	res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (!res)
		return (0);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
			res[j++] = argv[i][k++];
		if (i <= argc - 1)
			res[j] = ' ';
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}*/

