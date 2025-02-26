/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:02:12 by mikurek           #+#    #+#             */
/*   Updated: 2025/02/26 20:29:30 by mikurek          ###   ########.fr       */
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

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	**content;
	int		collectibles;
}			t_map;

typedef struct s_game
{
	t_map	*map;
}			t_game;

t_map	*ft_load_map(char *map_src);
int		ft_check_rules(t_map *map);
int		ft_check_reachable(t_map *map);
void	free_map(t_map *map);
void	init_data(t_game *game, char **argv);

#endif