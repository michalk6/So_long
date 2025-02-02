/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:53:59 by mikurek           #+#    #+#             */
/*   Updated: 2025/01/11 19:18:06 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_format(char format, va_list arg)
{
	if (format == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (format == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (format == 'p')
		return (ft_putptr((unsigned long) va_arg(arg, void *)));
	if (format == 'd')
		return (ft_putdecimal(va_arg(arg, int)));
	if (format == 'i')
		return (ft_putint(va_arg(arg, int)));
	if (format == 'u')
		return (ft_putunsignedint(va_arg(arg, unsigned int)));
	if (format == 'x')
		return (ft_puthex(va_arg(arg, int)));
	if (format == 'X')
		return (ft_puthex_upper(va_arg(arg, int)));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		result;
	va_list	argptr;

	result = 0;
	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result += ft_format(*format, argptr);
		}
		else
			result += ft_putchar(*format);
		format++;
	}
	va_end(argptr);
	return (result);
}
