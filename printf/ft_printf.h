/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:59 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/24 14:30:57 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>


int check_part(const char *str);
char cspdiux(char c);
int print_arg(va_list ptr_args, char c);
int ft_printf(const char *str, ...);
int count_digits_int(int n);
int	int_putnbr(int n);
int count_digits_unsign(unsigned int n);
int	int_putnbr_unsign(unsigned int n);
int	count_hex(long unsigned int n);
int	int_puthex(char c, unsigned int n);



# endif

