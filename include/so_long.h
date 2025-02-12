/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:02:12 by mikurek           #+#    #+#             */
/*   Updated: 2025/02/11 23:25:51 by mikurek          ###   ########.fr       */
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
}	t_map;

typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

t_map	*ft_load_map(char *map_src);
int		ft_is_closed(t_map *map);
int		ft_has_player_exit(t_map *map);
int		ft_has_collectible(t_map *map);
int		ft_check_reachable(t_map *map);

#endif