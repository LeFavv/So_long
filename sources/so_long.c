/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/30 00:47:07 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_command_line_params(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Error\nNo map file found\n");
		return (0);
	}
	else if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
		return (0);
	}
	else if (!check_name(argv[1]))
	{
		printf("Error\nThe map must be a .ber file\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width * TILE_SIZE , game->win_height * TILE_SIZE, "So Long");
	mlx_loop(game->mlx);
}
