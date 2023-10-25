/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:31 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/25 15:43:31 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
#endif

# include "get_next_line_utils.c"

char    *get_next_line(int fd);
size_t  ft_strlen(const char*str);
char    *ft_strjoin(char const *s1, char const *s2);
int     count_till_nl(char *str);
char    *read_till_nl(int fd, char *str);








#endif

