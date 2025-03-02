/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:27:19 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 21:20:40 by mikurek          ###   ########.fr       */
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

void	free_textures(t_game *game)
{
	// if (!game->textures)
	// 	return;
	// if (game->textures->wall)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->wall);
	// if (game->textures->floor)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->floor);
	// if (game->textures->character_up)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_up);
	// if (game->textures->character_down)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_down);
	// if (game->textures->character_left)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_left);
	// if (game->textures->character_right)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->character_right);
	// if (game->textures->collectible)
	// 	mlx_destroy_image(game->window->mlx_ptr, game->textures->collectible);

	// free(game->textures);
	// game->textures = NULL;

	// mlx_destroy_image(game->window->mlx_ptr, game->textures->wall);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->floor);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->character_up);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->character_down);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->character_left);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->character_right);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures->collectible);
	// mlx_destroy_image(game->window->mlx_ptr, game->textures);

	free(game->textures->wall);
	free(game->textures->floor);
	free(game->textures->character_up);
	free(game->textures->character_down);
	free(game->textures->character_left);
	free(game->textures->character_right);
	free(game->textures->collectible);
	free(game->textures);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	free_textures(game);
	free(game->window->mlx_ptr);
	free(game->window);
	free(game->player);
}
