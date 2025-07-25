/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/16 12:58:15 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_command_line_params(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error\nNo map file found\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nToo many arguments\n");
		return (0);
	}
	else if (!check_name(argv[1]))
	{
		ft_printf("Error\nThe map must be a .ber file\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (!check_command_line_params(argc, argv))
		exit (1);
	game = malloc(sizeof(t_game));
	if (!game)
		return (ft_printf("Error\nMalloc failed\n"), 1);
	init_game(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (end_game(game, "Error\nmlx_init failed\n", 1), 1);
	game->map = load_map(argv[1]);
	if (!game->map || !game->map[0])
		return (end_game(game, "Error\nMap NULL\n", 1), 1);
	if (!error_check(game->map, argv[1], game))
		return (end_game(game, "Error\nInvalid map\n", 1), 1);
	init_image_1(game);
	game->win = mlx_new_window(game->mlx, game->win_width,
			game->win_height, "So Long");
	if (!game->win)
		return (end_game(game, "Error\nmlx_new_window failed\n", 1), 1);
	render_map(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop(game->mlx);
}
