/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:48:44 by mikurek           #+#    #+#             */
/*   Updated: 2025/01/28 23:49:43 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"

int		ft_putchar(int i);
int		ft_putstr(char *str);
int		ft_putunsignednum_base(unsigned long n, char *base);
int		ft_putunsignedint(unsigned int i);
int		ft_putdecimal(int n);
int		ft_putint(int i);
int		ft_putunsignedhex(unsigned long i);
int		ft_puthex(int n);
int		ft_putunsignedhex_upper(unsigned long i);
int		ft_puthex_upper(int n);
int		ft_putptr(unsigned long n);
int		ft_printf(const char *format, ...);
char	*get_next_line(int fd);

#endif