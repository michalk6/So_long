/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:27:19 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/03 22:00:23 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map(t_game *game, char **argv)
{
	if (ft_strlen(argv[1]) < 4
		|| ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber"))
	{
		ft_printf("Map must be in .ber format\n");
		exit(EXIT_FAILURE);
	}
	game->map = ft_load_map(argv[1]);
}

static void	read_initial_coordinates(t_game *game)
{
	size_t	i;
	size_t	j;
	char	**map_content;

	map_content = game->map->content;
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (map_content[i][j] == 'P')
			{
				game->player->x = j;
				game->player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (game->player == NULL)
		exit(EXIT_FAILURE);
	game->player->moves = 0;
	game->player->x = 0;
	game->player->y = 0;
	read_initial_coordinates(game);
}

void	init_textures(t_game *game)
{
	int	x;
	int	y;

	game->textures = malloc(sizeof(t_textures));
	if (game->textures == NULL)
		exit(EXIT_FAILURE);
	game->textures->wall = mlx_xpm_file_to_image(
			game->window->mlx_ptr, WALL, &x, &y);
	game->textures->floor = mlx_xpm_file_to_image(
			game->window->mlx_ptr, FLOOR, &x, &y);
	game->textures->exit_open = mlx_xpm_file_to_image(
			game->window->mlx_ptr, EXIT_OPEN, &x, &y);
	game->textures->exit_close = mlx_xpm_file_to_image(
			game->window->mlx_ptr, EXIT_CLOSE, &x, &y);
	game->textures->character_up = mlx_xpm_file_to_image(
			game->window->mlx_ptr, CHARACTER_UP, &x, &y);
	game->textures->character_down = mlx_xpm_file_to_image(
			game->window->mlx_ptr, CHARACTER_DOWN, &x, &y);
	game->textures->character_left = mlx_xpm_file_to_image(
			game->window->mlx_ptr, CHARACTER_LEFT, &x, &y);
	game->textures->character_right = mlx_xpm_file_to_image(
			game->window->mlx_ptr, CHARACTER_RIGHT, &x, &y);
	game->textures->collectible = mlx_xpm_file_to_image(
			game->window->mlx_ptr, COLLECTIBLE, &x, &y);
}

void	init_window(t_game *game)
{
	game->window = malloc(sizeof(t_window));
	if (game->window == NULL)
		exit(EXIT_FAILURE);
	game->window->mlx_ptr = mlx_init();
	game->window->width = game->map->width * PX_IMG;
	game->window->height = game->map->height * PX_IMG;
	game->window->win_ptr = mlx_new_window(
			game->window->mlx_ptr, game->window->width,
			game->window->height, "so_long");
}
