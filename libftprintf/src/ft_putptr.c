/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:28:29 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/15 17:51:31 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putptr(unsigned long n)
{
	if (!n)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putunsignedhex(n));
}
