/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignedhex_upper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:23:04 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/14 23:10:25 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putunsignedhex_upper(unsigned long i)
{
	char	*base;

	base = "0123456789ABCDEF";
	return (ft_putunsignednum_base(i, base));
}
