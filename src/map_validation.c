/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:22:29 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 20:15:05 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_fill_reacheable_area(char **content, int i, int j)
{
	content[i][j] = 'P';
	if (content[i - 1][j] != '1'
		&& content[i - 1][j] != 'E' && content[i - 1][j] != 'P')
		ft_fill_reacheable_area(content, i - 1, j);
	if (content[i + 1][j] != '1'
		&& content[i + 1][j] != 'E' && content[i + 1][j] != 'P')
		ft_fill_reacheable_area(content, i + 1, j);
	if (content[i][j - 1] != '1'
		&& content[i][j - 1] != 'E' && content[i][j - 1] != 'P')
		ft_fill_reacheable_area(content, i, j - 1);
	if (content[i][j + 1] != '1'
		&& content[i][j + 1] != 'E' && content[i][j + 1] != 'P')
		ft_fill_reacheable_area(content, i, j + 1);
}

char	**ft_duplicate_content(t_map *map)
{
	char	**content;
	size_t	i;

	content = malloc((map->height + 1) * sizeof(char *));
	if (content == NULL)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		content[i] = ft_strdup(map->content[i]);
		i++;
	}
	content[i] = NULL;
	return (content);
}

int	ft_check_collectibles_reachable(char **reachable_content)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (reachable_content[i])
	{
		j = 0;
		while (reachable_content[i][j])
		{
			if (reachable_content[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_exit_reachable(char **reachable_content, t_map *map)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 1;
	while (i < map->height && reachable_content[i][j] != 'E')
	{
		j = 1;
		while (j < map->width && reachable_content[i][j] != 'E')
			j++;
		if (reachable_content[i][j] == 'E')
			break ;
		i++;
	}
	if (reachable_content[i + 1][j] == 'P')
		return (1);
	if (reachable_content[i - 1][j] == 'P')
		return (1);
	if (reachable_content[i][j + 1] == 'P')
		return (1);
	if (reachable_content[i][j - 1] == 'P')
		return (1);
	return (0);
}

int	ft_check_reachable(t_map *map)
{
	char	**content;
	size_t	i;
	size_t	j;
	int		collectibles;
	int		exit;

	if (!ft_check_rules(map))
		return (0);
	i = 1;
	j = 1;
	content = ft_duplicate_content(map);
	while (i < map->height && content[i][j] != 'P')
	{
		j = 1;
		while (j < map->width && content[i][j] != 'P')
			j++;
		if (content[i][j] == 'P')
			break ;
		i++;
	}
	ft_fill_reacheable_area(content, i, j);
	collectibles = ft_check_collectibles_reachable(content);
	exit = ft_check_exit_reachable(content, map);
	ft_free_str_table(content);
	return (collectibles && exit);
}
