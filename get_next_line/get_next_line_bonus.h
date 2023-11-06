/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:19:48 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/06 18:20:27 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *dest, char *src, size_t n);
int		count_till_nl(char *str);
int		count_after_nl(char *str);
int		check_nl_escape(char *str);
char	*copy_first_line(char *str);
char	*read_all(int fd, char *str);
char	*update_statik_str(char *old_str);
char	*get_next_line(int fd);

#endif
