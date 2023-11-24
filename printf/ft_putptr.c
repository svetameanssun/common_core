/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:55 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/24 14:29:47 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_puthex_ptr(long unsigned int n, int m)
{
    
}


int	ft_putptr(long unsigned int n)
{
    int count;

    if (n == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
    count = ft_puthex_ptr
    
}