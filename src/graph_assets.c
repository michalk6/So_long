/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:14:11 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 20:14:31 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_player(t_game *game, int x, int y, int dir)
{
	void	*player_image;

	if (dir == XK_w)
		player_image = game->textures->character_up;
	else if (dir == XK_s)
		player_image = game->textures->character_down;
	else if (dir == XK_a)
		player_image = game->textures->character_left;
	else if (dir == XK_d)
		player_image = game->textures->character_right;
	else
		player_image = game->player;
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
		player_image, x * PX_IMG, y * PX_IMG);
}

void	draw_collectable(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->collectible,
		x * PX_IMG, y * PX_IMG);
}

void	draw_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->wall,
		x * PX_IMG, y * PX_IMG);
}

void	draw_exit(t_game *game, int x, int y)
{
	if (game->map->collectibles > 0)
		mlx_put_image_to_window(game->window->mlx_ptr,
			game->window->win_ptr, game->textures->exit_close,
			x * PX_IMG, y * PX_IMG);
	else
		mlx_put_image_to_window(game->window->mlx_ptr,
			game->window->win_ptr, game->textures->exit_open,
			x * PX_IMG, y * PX_IMG);
}

void	draw_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->window->mlx_ptr,
		game->window->win_ptr, game->textures->floor,
		x * PX_IMG, y * PX_IMG);
}
