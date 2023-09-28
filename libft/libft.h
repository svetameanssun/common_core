/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:26:59 by stitovsk          #+#    #+#             */
/*   Updated: 2023/09/28 19:54:52 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief This function changes an int to positive
 * 
 * @param j The int to change
 * @return int The int changed
 */
int	ft_abs(int j);
/**
 * @brief This function transforms a string ascii into an integer 
 * 
 * @param nptr the string to change
 * @return int The int returned
 */
int	ft_atoi(const char *nptr);
/**
 * @brief 
 * 
 * @param s 
 * @param n 
 */
void	ft_bzero(void *s, int n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isspace(int c);
void *ft_calloc(size_t nelem, size_t elsize);
void	*ft_memchr(const void *s, int c, size_t n);
int	    ft_memcmp(const void *s1, const void *s2, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *s, size_t c, size_t n);
void ft_putchar_fd(char c, int fd);
void    ft_putchar(char c);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int nb, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
char    *ft_strcpy(char *dest, char *src);
char *ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_tolower(int c);
int ft_toupper(int c);

#endif 