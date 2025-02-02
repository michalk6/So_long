/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:25:18 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/07 14:25:18 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	size_t	total_size;

	total_size = nmemb * size;
	if (size != 0 && (total_size) / size != nmemb)
	{
		return (0);
	}
	result = malloc(total_size);
	if (result == 0)
		return (0);
	ft_bzero(result, total_size);
	return (result);
}
