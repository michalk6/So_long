/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:27:05 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 20:42:33 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	valid_move(t_game *game, int new_x, int new_y)
{
	if (game->map->content[new_y][new_x] == '1')
		return (0);
	if (
		game->map->content[new_y][new_x] == 'E'
		&& game->map->collectibles != 0
	)
		return (0);
	return (1);
}

void	move(t_game *game, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = game->player->x;
	old_y = game->player->y;
	if (game->map->content[new_y][new_x] == 'C')
		game->map->collectibles--;
	if (
		game->map->content[new_y][new_x] == 'E'
		&& game->map->collectibles == 0
	)
	{
		ft_printf("Congratulations you finished level\n");
		exit_game(game);
	}
	game->map->content[old_y][old_x] = '0';
	game->map->content[new_y][new_x] = 'P';
	game->player->x = new_x;
	game->player->y = new_y;
	game->player->moves++;
	ft_printf("moves %d\n", game->player->moves);
}
