/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:27:33 by mikurek           #+#    #+#             */
/*   Updated: 2024/12/07 18:27:33 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(const char *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			counter++;
			while (*s && *s != c)
				s++;
		}
	}
	return (counter);
}

char	*ft_add_word(char const *s, char c)
{
	char	*word;
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = ft_substr(s, 0, len);
	return (word);
}

void	ft_free_str_table(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split_array(char **split, const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split[i] = ft_add_word(s, c);
			if (split[i] == 0)
			{
				ft_free_str_table(split);
				return (0);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	word_count;

	if (!s)
		return (0);
	word_count = ft_count_words(s, c);
	split = malloc((word_count + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	if (!ft_split_array(split, s, c))
		return (0);
	return (split);
}
