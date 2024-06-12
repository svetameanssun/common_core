/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_sl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:56:01 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/12 12:01:11 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

size_t	ft_strlen_sl(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	return (count);
}

/*int main()
{
    printf("%ld\n",ft_strlen_sl("sveta\n"));
    printf("%ld\n",ft_strlen_sl("sveta"));
    return(0);
}*/
