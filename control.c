/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:19 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 23:46:01 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	move_up(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x;
	new_y = game->player->y - 1;
	if (!valid_move(game, new_x, new_y))
		return ;
	move(game, new_x, new_y);
	render_map(game, XK_w);
}

static void	move_down(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x;
	new_y = game->player->y + 1;
	if (!valid_move(game, new_x, new_y))
		return ;
	move(game, new_x, new_y);
	render_map(game, XK_s);
}

static void	move_left(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x - 1;
	new_y = game->player->y;
	if (!valid_move(game, new_x, new_y))
		return ;
	move(game, new_x, new_y);
	render_map(game, XK_a);
}

static void	move_right(t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player->x + 1;
	new_y = game->player->y;
	if (!valid_move(game, new_x, new_y))
		return ;
	move(game, new_x, new_y);
	render_map(game, XK_d);
}

int	control_key_function(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_game(game);
	if (keysym == XK_w)
		move_up(game);
	if (keysym == XK_s)
		move_down(game);
	if (keysym == XK_a)
		move_left(game);
	if (keysym == XK_d)
		move_right(game);
	return (0);
}
