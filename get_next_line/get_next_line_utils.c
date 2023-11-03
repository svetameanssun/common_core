/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:41 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/03 16:21:04 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	
	if (!str)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
	{
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (i < (ft_strlen(s1) + ft_strlen(s2)))
	{
		new[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	new[i] = '\0';
	free(s1);
	return (new);
}

int check_nl_escape(char *str)
{
	int i;

	i = 0;
    if(!str)
        return (0);
	while(str[i] != '\0')
	{
		if (str[i] == '\n')
        {
			//printf("check_nl_escape done\n");
			return (1);
        }
		i++;
	}
	//printf("check_nl_escape done\n");
	return (0);
}
int count_after_nl(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(str[i] != '\n' && str[i] != '\0')
    {
        i++;
    }
	if (str[i] == '\n')
	{	
		i++;
		while(str[i] != '\0')
    	{
			i++;
        	count++; 
    	}
	}
    return (count); 
}
int count_till_nl(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
    {
        i++;
		
    }
    if (str[i] == '\0')
	{
        return (i);
	}
	return(++i);// why not i++ ?
}
/*int main()
{
    //int fd_open = open("file_to_read.txt", O_RDONLY);
    char *str;
	//char * line;
	char c = 'a';

	str = malloc(1 * (7));
	int i = 0;
	while(i < 7)
	{
		str[i] = c;
		i++;
		c++;
	}
	str[3] = '\n';
	int before = count_till_nl(str);
	int after = count_after_nl(str);
	//printf("%d\n", before);
	//printf("%d\n", after);
	//printf("%s\n",str);
	str = copy_first_line(str);
	printf("%s",str);

    
}*/