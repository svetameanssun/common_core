/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:03:32 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/28 13:56:47 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

/*int check_part(char c)
{
    if(str[0] == '%' && cspdiux(str[1]))
        return(cspdiux(str[1]));
    return(0);
}*/

char cspdiux(char c)
{
    return(c == 'c' || c == 's'|| c == 'd'|| c == 'i'
    || c == 'u'|| c == 'x'|| c == 'X'|| c == '%'|| c == 'p');
}