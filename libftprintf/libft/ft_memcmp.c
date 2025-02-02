/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:36:22 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/06 20:36:22 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	if (n == 0)
		return (0);
	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (i < n - 1 && ptr1[i] == ptr2[i])
	{
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
