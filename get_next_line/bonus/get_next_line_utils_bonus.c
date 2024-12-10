/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:17:29 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/07 17:42:27 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_strlen(char *str)
{
	
	int i;
	
	i = 0;
	if (!str) // important!
		return(0);
	while(str[i])
	{
		i++;
	}
	return (i);
}

int has_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0); // also important!
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int count_till_nl(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return(++i);
		i++;
	}
	return (i);
}

int count_after_nl(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	while(str[i])
	{
		i++;
		count++;
	}
	return(count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	size_s1;
	size_t	size_s1_s2;

	size_s1 = ft_strlen(s1);
	size_s1_s2 = ft_strlen(s1) + ft_strlen(s2);
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
