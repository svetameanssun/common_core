/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:30:21 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/02 17:54:46 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_len(int n)
{
	int	n_len;

	if (n == 0)
		return (1);
    n_len = 0;
	if (n < 0)
	{
		n = -n;
        n_len++;
	}
	while (n > 0)
	{
		n = n / 10;
		n_len++;
	}
	return (n_len);
}

char	*ft_itoa(int n)
{
	char        *str;
    int         i;
    int         final;
    long int    aux;
    
    aux = n;
    if (n < 0)
    {
        str = (char*)malloc(sizeof(char)*(ft_int_len(n) + 1 + final));
        str[0] = '-';
        n = n * -1;
        final++;
        printf(" n IN the n < 0 if contition:  %d\n", n);
        printf("\n");
    }
    str = (char*)malloc(sizeof(char)*(ft_int_len(n) + 1));
    printf("ESTO ES ft_int_len: %d\n",ft_int_len(n));
    if (str == 0)
        return (0);
    if (n == 0)
        str[0] = '0';
    final = 0;
    
    printf("final  %d\n", final);
    printf("\n");
    i = ft_int_len(n) - 1;
    printf(" n AFTER the n < 0 if contition: %d\n", n);
    printf(" i which iquals ft_int_len(n) - 1: %d\n", i);
    printf("\n");
    while (i > final)
    {
        printf(" i IN while: %d\n", i);
        str[i] = n % 10 + '0';
        printf(" str[%i] %c\n", i,str[i]);
        n = n/10;
        printf("n after n/10: %d\n", n);
        i--;
    }
    printf("\n");
    printf("i AFTER while: %d\n", i);
    str[ft_int_len(aux)] = '\0';
    return (str);
}
int main(void)
{
 int c = -123;
 printf("%s",ft_itoa(c));
 return 0;
}
