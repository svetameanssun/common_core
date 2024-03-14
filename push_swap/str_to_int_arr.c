/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:30:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/13 20:38:36 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	funct_atoi(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = sign * -1;
		str++;
	}
	if (*str == '+')
		str++;
	while (*str && *str != ' ')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}

int	numbers_unique(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i] == arr[j] && i != j)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	input_valid(char *str)
{
	int	i;
	
	i = 0;
	if (!str[i] || str[i] == 32)
		return (0);
	while (str[i])
	{
		if (is_digit(str[i]))
			i++;
		else
		{
			if ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1])
				&& i == 0 || str[i - 1] == ' ')
				i++;
			else if (str[i] == ' ' && (is_digit(str[i + 1])
					|| str[i + 1] == '-' || str[i + 1] == '+') && is_digit(str[i - 1]))
				i++;
			else
				return (0);
		}
	}
	return (i);
}

int	word_count(char *str)
{
	int	word_cnt;

	word_cnt = 0;
	while (str[word_cnt])
	{
		if (is_digit(str[word_cnt])
			&& (str[word_cnt + 1] == ' ' || str[word_cnt + 1] == '\0'))
			word_cnt++;
		str++;
	}
	return (word_cnt);
}

int	*str_to_numbers(char *str)
{
	int	i;
	int	j;
	int	word_cnt;
	int	*res;

	i = 0;
	j = 1;
	if (!input_valid(str))
		return (0);
	word_cnt = word_count(str);
	res = (int *)malloc(sizeof(int) * (word_cnt));
	if (res == 0)
		return (0);
	res[0] = funct_atoi(str + 0);
	while (j < word_cnt)
	{
		while (str[i] && str[i] != ' ')
			i++;
		i++;
		res[j] = funct_atoi(str + i);
		j++;
	}
	if (!numbers_unique(res, word_cnt))
		return (0);
	return (res);
}

int	united_str_size(int arg_num, char **arguments)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
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
}

char	*words_to_str(int argc, char **argv)
{
	int		i;
	int		j;
	int		res_size;
	char	*res;
	int		k;

	i = 1;
	j = 0;
	k = 0;
	res_size = united_str_size(argc, argv);
	res = (char *)malloc(sizeof(char) * (res_size + 1));
	if (!res)
		return (0);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k])
			res[j++] = argv[i][k++];
		if (i < argc - 1)
			res[j] = ' ';
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

int	main(int argc, char **argv)
{
	int word_cnt = 0;
	int i = 0;
	int *arr;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (str_to_numbers(argv[1]) == 0)
		{
			ft_printf("Error");
			return (0);
		}
		arr = str_to_numbers(argv[1]);
		word_cnt = word_count(argv[1]);
		ft_printf("%p\n", arr);
	}
	if (argc > 2)
	{
		if (str_to_numbers(words_to_str(argc, argv)) == 0)
		{
			ft_printf("Error");
			return (0);
		}
		arr = str_to_numbers(words_to_str(argc, argv));
		word_cnt = word_count(words_to_str(argc, argv));
		ft_printf("%d\n", word_cnt);
		ft_printf("%p\n", arr);
	}

	while (i < word_cnt)
	{
		ft_printf("%d\n", arr[i++]);
	}
	ft_printf("%d", ft_isdigit('0'));
}
