/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:28:10 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/05 16:44:55 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//int check_c(char const *s, char c);
/*size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}*/
/*char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t    i;
    char            *new;

    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    if (start >=  ft_strlen(s))
    {
        new = malloc(1);
        if (!new) 
            return(0);
        new[0] = '\0';
        return(new);
    }
    new = malloc(sizeof(char)*(len + 1));
    if (new == NULL)
		return (NULL);
    i = 0;
    while (s[start] && i < len)
        {
            new[i] = s[start];
            i++;
            start++;
        }
    new[i] = '\0';
    return (new); 
}*/


int ft_count_elems(char const *s, char c)
{
    int i;
    int count;
    
    i = 0;
    count = 0;
   
    while (s[i]!='\0')
    {
        if (s[i] != c )
        {
            
            while (s[i] != c && s[i]!='\0')
                i++;
            count++;
        }
        else
            i++;
    }
    return (count);
}
static void ft_free(char ** str , int str_ind)
{
    while (str_ind-- > 0)
        free(str[str_ind]);
    free(str);
}
size_t ft_substr_len(char const *s, char c)
{
    int i;
    size_t count;

    i = 0;
    count = 0;
    while (s[i] == c && s[i] != '\0')
        i++;
    while (s[i] !=c && s[i] != '\0')
    {
        count++;
        i++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{   
    char    **double_dimen;
    int     count;
    int     elem_num;
    
    
    
    count = 0;
    elem_num = ft_count_elems(s,c);
    double_dimen = (char**)malloc(sizeof(char*)*(ft_count_elems(s,c) + 1));
    if  (double_dimen == NULL)
        return(NULL);
   // while(*s + i  != '\0')
    while(count < elem_num)
    {
        //if (*s + i != c && count < ft_count_elems(s,c))
        while (*s == c)
			s++;
        double_dimen[count] = ft_substr(s, 0, ft_substr_len(s, c));
		if (!(double_dimen[count]))
		{
			ft_free(double_dimen, count);
			return (0);
		}
		while(*s != c && *s)
            s++;
        count++;
    }
    double_dimen[count] = NULL;
    return (double_dimen);
    }
/*int main(void)
{
    char  str[100] = "Hello!";
    char c = ' ';
    char ** dim;
    dim = ft_split(str, c);
    
    printf("%d",ft_count_elems(str, c));
    printf("%s",dim[0]);
    return 0;
}*/