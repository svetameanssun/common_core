/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:26:59 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/14 19:26:15 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_abs(int j);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
void	*ft_memset(void *s, int c, int n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, int n);
void    ft_putchar(char c);
void    ft_putstr(char *str);
char    *ft_strcpy(char *dest, char *src);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int ft_strlen(char *str);
int ft_tolower(int c);
int ft_toupper(int c);

#endif 