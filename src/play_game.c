/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:17:33 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 20:15:02 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	play_game(t_game *game)
{
	render_map(game, XK_s);
	mlx_key_hook(game->window->win_ptr, control_key_function, game);
	mlx_hook(game->window->win_ptr, 17, 0, exit_game, game);
	mlx_loop(game->window->mlx_ptr);
}
