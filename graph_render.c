/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:49:39 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 20:17:01 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	display_stats(t_game *game, int dir)
{
	int i;

	ft_printf("%c pressed\n", dir);
	i = 0;
	if (game->map != NULL)
	{
		while ((game->map->content)[i] != NULL)
		{
			ft_printf("%s\n", (game->map->content)[i]);
			i++;
		}
		ft_printf("collectibles = %d\n", game->map->collectibles);
		ft_printf("map size %d x %d\n", game->map->width, game->map->height);
		ft_printf("player initial coordinates x = %d, y = %d\n"
			, game->player->x, game->player->y);
		ft_printf("moves %d\n", game->player->moves);
	}
}

static void	draw_asset(t_game *game, int x, int y, int dir)
{
	char	elem;

	elem = game->map->content[y][x];
	if (elem == '1')
		draw_wall(game, x, y);
	else if (elem == 'C')
		draw_collectable(game, x, y);
	else if (elem == 'P')
		draw_player(game, x, y, dir);
	else if (elem == 'E')
		draw_exit(game, x, y);
	else if (elem == '0')
		draw_floor(game, x, y);
}

void	render_map(t_game *game, int dir)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (game->map->content[y][x])
		{
			draw_asset(game, x, y, dir);
			x++;
		}
		y++;
	}
	display_stats(game, dir);
}