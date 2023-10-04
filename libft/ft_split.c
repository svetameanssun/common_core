/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:28:10 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/04 19:53:45 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_count_elems(char const *s, char c)
{
    int i;
    int j;
    int count;
    
    i = 1;
    j = 0;
    count = 0;
    while (s[j]!='\0')
    {
        if (s[j] != c && (s[i] == c || s[i] == '\0'))
            count++;
        i++;
        j++;
    }
    return (count);
}
char *gen_string(char const *str, int n, char c)
{
    char *res;
    int j;

    res = (char*)malloc(sizeof(char) * (n + 2));
    j = 0;
    while(str[j] != c)
        res[j] = str[j];
        j++;
    res[j] = '\0';
    return (res);
    
}

char **ft_split(char const *s, char c)
{   
    char    **double_pointer;
    int     count;
    int     i;
    int     j;
    int     k;

    count = 1;
    i = 0;
    j = 0;
    k = 0;
    double_pointer = (char**)malloc(sizeof(char*)*(ft_count_elems(s,c) + 1));
    if (double_pointer == NULL)
        return(NULL);
    while (s[i] != '\0' && double_pointer)
    {  
        while((s[i+j] != c) && (s[count+j] != c || s[count+j] != '\0'))
        {
            j++;
        }
        double_pointer[k] = gen_string(s + i, j, c);
        k++;
        i = i + j;
        count = count + j;
        j = 0;
    }
    return (double_pointer);
}
/*int main(void)
{
    char  str[100] = "      add bd cd d    ";
    char c = ' ';
    printf("%d",ft_count_elems(str, c));
    return 0;
}*/