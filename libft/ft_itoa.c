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
    printf("%d\n", n);
    printf("ft_int_len(n) = %d\n",ft_int_len(n));
    printf("\n");
    aux = n;

    printf("if (n < 0)\n");
    printf("{\n");
    final = 0;
    str = (char*)malloc(sizeof(char)*(ft_int_len(aux) + 1));
    if (n < 0)
    {
        str[0] = '-';
        n = n * -1;
        final++;
        printf("-n = %d\n", n);
        printf("\n");
    }
     printf("}\n");
    
    printf("ft_int_len(aux) = %d\n",ft_int_len(aux));
    if (str == 0)
        return (0);
    if (n == 0)
        str[0] = '0';
    
    printf("final = %d\n", final);
    printf("\n");
    i = ft_int_len(aux) - 1;
    printf("n = %d\n", n);
    printf("i = %d\n", i);
    printf("\n");
    printf("while (i > final)\n");
    printf("{\n");
    while (i >= final)
    {
        printf("i = %d\n", i);
        str[i] = n % 10 + '0';
        printf("str[%i] = %c\n", i,str[i]);
        printf("%d/10: = ", n);
        n = n/10;
        printf("%d\n", n);
        i--;
        printf("\n");
    }
    printf("}\n");
    printf("\n");
    printf("i AFTER while: %d\n", i);
    str[ft_int_len(aux)] = '\0';
    return (str);
}
int main(void)
{
 int c = 0;
 printf("%s",ft_itoa(c));
 return 0;
}
