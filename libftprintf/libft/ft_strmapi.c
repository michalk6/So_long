/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:25:24 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/11 20:26:43 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*strmap;
	size_t	i;

	len = ft_strlen(s);
	strmap = malloc((len + 1) * sizeof(char));
	if (!strmap)
		return (0);
	i = 0;
	while (i < len)
	{
		strmap[i] = f(i, s[i]);
		i++;
	}
	strmap[i] = 0;
	return (strmap);
}
