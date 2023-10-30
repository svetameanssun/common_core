/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:31 by stitovsk          #+#    #+#             */
/*   Updated: 2023/10/30 14:00:33 by stitovsk         ###   ########.fr       */
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

size_t  ft_strlen(const char*str);
char    *ft_strjoin(char const *s1, char const *s2);
char	*copy_str(char *dest, char *src, size_t size);
int     count_till_nl(char *str);
int     count_after_nl(char *str);
int     check_nl_escape(char *str);
char    *copy_first_line(char * str);
char    *read_till_nl(int fd, char *str);
char    *update_statik_str(char *old_str);
char    *get_next_line(int fd);



#endif

