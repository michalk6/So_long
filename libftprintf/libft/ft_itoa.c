/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:44:41 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/07 18:44:41 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_size(int n)
{
	size_t	size;

	if (n == 0)
		return (1);
	if (n < 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa_array(char *array, long long n, int size)
{
	int	i;

	if (n == 0)
		array[0] = '0';
	if (n < 0)
	{
		array[0] = '-';
		n *= -1;
	}
	i = 1;
	while (n != 0)
	{
		array[size - i] = (n % 10) + '0';
		i++;
		n /= 10;
	}
	array[size] = 0;
	return (array);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*itoa;

	size = ft_get_size(n);
	itoa = malloc((size + 1) * sizeof(char));
	if (itoa == 0)
		return (0);
	return (ft_itoa_array(itoa, n, size));
}
