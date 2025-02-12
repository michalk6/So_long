/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:44:17 by mikurek           #+#    #+#             */
/*   Updated: 2025/02/09 23:47:56 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	ft_is_closed(t_map *map)
{
	char	**content;
	size_t	i;

	content = map->content;
	i = 0;
	while (i < map->width)
	{
		if (content[0][i] != '1' || content[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (content[i][0] != '1' || content[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_has_player_exit(t_map *map)
{
	int		player;
	int		exit;
	size_t	i;
	size_t	j;

	player = 0;
	exit = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'P')
				player++;
			if (map->content[i][j] == 'E')
				exit++;
			if (player > 1 || exit > 1)
				return (0);
			j++;
		}
		i++;
	}
	return (player & exit);
}

int	ft_has_collectible(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->content[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
