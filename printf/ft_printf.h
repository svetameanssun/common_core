/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:20:59 by stitovsk          #+#    #+#             */
/*   Updated: 2023/11/30 17:04:52 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		print_arg(va_list ptr_args, char c);
char	cspdiux(char c);
int		int_putchar(char c);
int		int_putstr(char *str);
int		count_digits_int(int n);
int		int_putnbr(int n);
int		count_digits_unsign(unsigned int n);
int		int_putnbr_unsign(unsigned int n);
int		count_hex(long unsigned int n);
int		int_puthex(char c, long unsigned int n);
int		int_putptr(long unsigned int n);

#endif