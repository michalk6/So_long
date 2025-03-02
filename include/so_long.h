/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:02:12 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 23:47:14 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libftprintf/include/ft_printf.h"
# include "../../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

# define WALL				"assets/wall.xpm"
# define FLOOR				"assets/floor.xpm"
# define COLLECTIBLE		"assets/collectible.xpm"
# define EXIT_OPEN			"assets/exit_open.xpm"
# define EXIT_CLOSE			"assets/exit_close.xpm"
# define CHARACTER_UP		"assets/character_up.xpm"
# define CHARACTER_DOWN		"assets/character_down.xpm"
# define CHARACTER_LEFT		"assets/character_left.xpm"
# define CHARACTER_RIGHT	"assets/character_right.xpm"
# define PX_IMG 64

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	**content;
	int		collectibles;
}	t_map;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}	t_window;

typedef struct s_player
{
	int	x;
	int	y;
	int	moves;
}	t_player;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*exit_open;
	void	*exit_close;
	void	*character_up;
	void	*character_down;
	void	*character_left;
	void	*character_right;
	void	*collectible;
}	t_textures;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_player	*player;
	t_textures	*textures;
}	t_game;

t_map	*ft_load_map(char *map_src);
int		ft_check_rules(t_map *map);
int		ft_check_reachable(t_map *map);

void	init_data(t_game *game, char **argv);
void	init_map(t_game *game, char **argv);
void	init_player(t_game *game);
void	init_textures(t_game *s_game);
void	init_window(t_game *game);

void	play_game(t_game *game);
int		exit_game(t_game *game);
int		control_key_function(int keysym, t_game *game);
int		valid_move(t_game *game, int new_x, int new_y);
void	move(t_game *game, int new_x, int new_y);

void	render_map(t_game *game, int dir);
void	draw_player(t_game *game, int x, int y, int dir);
void	draw_collectable(t_game *game, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	draw_exit(t_game *game, int x, int y);
void	draw_floor(t_game *game, int x, int y);

void	free_map(t_map *map);
void	free_game(t_game *game);

#endif