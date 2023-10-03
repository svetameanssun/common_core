/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:28:10 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/02 19:28:10 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int ft_no_c_count(char const *s, char c)
{
    int     count;
    int     i;
    
    count = 0;
    i = 0;
    while (s[i] != '\0')
    { 
        if (s[i]!= c)
        {
            count++;
        }
        i++;
    }
    return (count);
}*/

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char **ft_split(char const *s, char c)
{   
    char    **double_pointer;
    int     count;
    int     i;
    int     j;

    count = 0;
    i = 0;
    j = 0;
    double_pointer = (char**)malloc(sizeof(char)*(ft_strlen(s) + 1));
    if (double_pointer == 0)
        return(0);
    
    while (s[i] != '\0')
    {   
        j = 0;
        while (s[i + j] != c)
        {   
            printf("s[%d + %d]\n",count,j);
            printf("double_pointer[%d][%d]\n",count,j);
            double_pointer[count][j] = s[i+j];
            j++;
        }
        i = i + j;
        count++;
    }
    double_pointer[count][j] = '\0';
    return (double_pointer);
}

int main(void)
{
    char  str[10] = "a b c d e";
    char c = ' ';
    printf("%d",ft_split(str,c));
    return 0;
}

