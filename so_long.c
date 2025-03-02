/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikurek <mikurek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:16:30 by mikurek           #+#    #+#             */
/*   Updated: 2025/03/02 20:55:04 by mikurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("No map has been chosen\n");
		return (EXIT_FAILURE);
	}
	init_data(&game, argv);
	play_game(&game);
	return (EXIT_SUCCESS);
}
