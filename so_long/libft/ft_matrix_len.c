/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svetameanssun <svetameanssun@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:13:20 by svetameanss       #+#    #+#             */
/*   Updated: 2024/06/10 20:03:05 by svetameanss      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix_len(char **matrix)
{
	int	count;

	count = 0;
	while (matrix[count] != NULL)
	{
		count++;
	}
	return (count);
}
/*int main()
{
	char * a = "aaaaaa";
	char * b = "bbbbbb";
	char * c = "cccccc";
	char * d = "dddddd";
	char * e = "eeeeee";
	char *matrix[6];
	matrix[0] = a;
	matrix[1] = b;
	matrix[2] = c;
	matrix[3] = d;
	matrix[4] = e;
	matrix[5] = NULL;
		
	int len = ft_matrix_len(matrix);
	printf("%d", len);
}*/