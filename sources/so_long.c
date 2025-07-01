/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/01 11:11:40 by vafavard         ###   ########.fr       */
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

	game = malloc(sizeof(t_game));
	game->mlx = mlx_init();
	if (argc == 2)
		game->map = load_map(argv[1]);
	set_map_width_height(game);
	game->win = mlx_new_window(game->mlx, game->win_width , game->win_height, "So Long");
	init_image(game);
	render_map(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	free(game);
}
