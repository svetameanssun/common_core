/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_int_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:30:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/03/21 18:13:08 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>*/
#include "push_swap.h"

int ft_error()
{
	ft_printf("error");
	exit(0);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}
int equal_str(char * s1, char *s2)
{
	int i;

	i = 0;
	while(s1[i] && s2[i])
	{
		if(s1[i]!=s2[i])
		{
			return(0);
		}
		i++;
	}
	return(i);
	
}

long	ft_atol(char *str)
{
	long res;
	int	sign;

	res = 0;
	sign = 1;
	/*if (equal_str(str, "-2147483648"))
		return(-2147483648);*/
	if (*str == '-')
	{
		sign = sign * (-1);
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

int	longs_unique(long *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		if (arr[i] > MAX || arr[i] < MIN)
			return(0);
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
	while (str[i] && str[i+1])
	{
		if (is_digit(str[i]))
			i++;
		else
		{
			if ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1])
				&& (i == 0 || str[i - 1] == ' '))
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
	int i;

	word_cnt = 0;
	i = 0;
	while (str[i] && str[i + 1])
	{
		if (is_digit(str[i]) && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			word_cnt++;
		}
		i++;
	}
	return (word_cnt);
}

long	*str_to_numbers(char *str)
{
	int	i;
	int	j;
	int	word_cnt;
	long	*res;

	i = 0;
	j = 1;
	if (!input_valid(str))
		return (0);
	word_cnt = word_count(str);
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
	if (!longs_unique(res, word_cnt))
	{
		free(res);
		return(0);
	}
		
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
}
