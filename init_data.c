/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:09:55 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 13:59:58 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

void	init_data(t_game *game, char **argv)
{
	init_map(game, argv);
	init_player(game);
	init_window(game);
	init_textures(game);
}
