/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:23:47 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/07 16:23:47 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matches_to_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

size_t	ft_get_sub_len(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (ft_matches_to_set(s1[i], set))
	{
		len--;
		i++;
		if (!s1[i])
			return (0);
	}
	while (s1[i])
		i++;
	i--;
	while (ft_matches_to_set(s1[i], set))
	{
		len--;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	char	*trim;

	len = ft_get_sub_len(s1, set);
	trim = malloc((len + 1) * sizeof(char));
	if (trim == 0)
		return (0);
	while (ft_matches_to_set(*s1, set))
		s1++;
	i = 0;
	while (i < len)
	{
		trim[i] = s1[i];
		i++;
	}
	trim[i] = 0;
	return (trim);
}
