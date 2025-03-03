/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:27:19 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 18:34:18 by mikurek          ###   ########.fr       */
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

static void	mlx_destroy_all(t_game *game)
{
	mlx_destroy_image(game->window->mlx_ptr, game->textures->wall);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->floor);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_up);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_down);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_left);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_right);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->collectible);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->exit_close);
	mlx_destroy_image(game->window->mlx_ptr, game->textures->exit_open);
	mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	mlx_destroy_display(game->window->mlx_ptr);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_all(game);
	free(game->window->mlx_ptr);
	free(game->textures);
	free(game->window);
	free(game->player);
}
