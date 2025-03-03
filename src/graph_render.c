/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:49:39 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 20:30:50 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_stats(t_game *game)
{
	char	*steps;
	char	msg[256];
	char	*info;

	info = "Exit is now open!";
	steps = ft_itoa(game->player->moves);
	ft_strlcpy(msg, "Number of moves: ", sizeof(msg));
	ft_strlcat(msg, steps, sizeof(msg));
	mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10,
		20, 0xFFFFFF, msg);
	if (game->map->collectibles == 0)
		mlx_string_put(game->window->mlx_ptr, game->window->win_ptr, 10,
			40, 0xFFFF70, info);
	free(steps);
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
	size_t	y;
	size_t	x;

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
	display_stats(game);
}
