/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:32:38 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/14 18:10:41 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putdecimal(int n)
{
	int		result;
	long	long_n;

	long_n = n;
	result = 0;
	if (long_n < 0)
	{
		ft_putchar('-');
		long_n *= -1;
		result++;
	}
	return (result + ft_putunsignedint(long_n));
}
