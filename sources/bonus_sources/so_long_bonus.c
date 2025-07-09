/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 13:31:55 by vafavard         ###   ########.fr       */
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
	init_game(game);
	game->mlx = mlx_init();
	if (check_command_line_params(argc, argv))
		game->map = load_map(argv[1]);
	else
		return (end_game(game, "Error\n", 1), 1);
	if (!error_check(game->map, argv[1], game))
	{
		// free_map(game->map);
		// free(game);
		return (1);
	}
	game->win = mlx_new_window(game->mlx, game->win_width , game->win_height, "So Long");
	init_image(game);
	init_image_bonus(game);
	render_map(game);
	render_map_bonus(game);
	mlx_loop_hook(game->mlx, update, game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	//erreur sur les premieres entrees clavier --> mlx_key_hook_loop ??
	mlx_loop(game->mlx);
	//makefile -> rajouter une regle pour make dans mlx
}
