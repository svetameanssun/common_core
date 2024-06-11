/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:41 by stitovsk          #+#    #+#             */
/*   Updated: 2024/06/11 22:04:45 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	size_s1;
	size_t	size_s1_s2;

	size_s1 = ft_strlen_gnl(s1);
	size_s1_s2 = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	new = (char *)malloc(sizeof(char) * (size_s1_s2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size_s1)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (size_s1_s2))
	{
		new[i] = s2[i - size_s1];
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

int	check_nl_escape(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	count_after_nl(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if (str[i] == '\n')
	{
		i++;
		while (str[i] != '\0')
		{
			i++;
			count++;
		}
	}
	return (count);
}

int	count_till_nl(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		return (1);
	}
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (i);
	}
	return (++i);
}
