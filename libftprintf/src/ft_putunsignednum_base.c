/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednum_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:27:28 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/14 23:11:21 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunsignednum_base(unsigned long n, char *base)
{
	int				result;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	result = 0;
	if (n >= base_len)
		result += ft_putunsignednum_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
	result++;
	return (result);
}
