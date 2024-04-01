/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_and_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:23:04 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/01 13:55:40 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}



int	is_space(int c)
{
	return (c == ' ');
}

int	end_or_space(int c)
{
	if (is_space(c))
		return (c);
	else if (c == '\0')
		return (1);
	else
		return(0);
}

int	plus_or_minus(int c)
{
	if (c == '+')
		return (c);
	else if (c == '-')
		return(c);
	else
		return(0);
}
