/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:30:21 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/06 13:07:10 by stitovsk         ###   ########.fr       */
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

char	*generate_string(char *str, int final, long int aux, int n)
{
	int	i;

	i = ft_int_len(n) - 1;
	while (i >= final)
	{
		str[i] = aux % 10 + '0';
		aux = aux / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			final;
	long int	aux;

	aux = n;
	final = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(sizeof(char) * (ft_int_len(aux) + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		aux = aux * -1;
		final++;
	}
	if (n == 0)
		str[0] = '0';
	str = generate_string(str, final, aux, n);
	str[ft_int_len(n)] = '\0';
	return (str);
}
/*int main(void)
{
 int c = 0;
 printf("%s",ft_itoa(c));
 return (0);
}*/
