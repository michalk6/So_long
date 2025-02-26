/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:27:19 by mikurek           #+#    #+#             */
/*   Updated: 2025/02/26 23:42:49 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	free_map(t_map *map)
{
	char	**to_free;

	to_free = map->content;
	free(map);
	map = NULL;
	ft_free_str_table(to_free);
	to_free = NULL;
}
