/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:08:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/01 10:26:10 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 53) //ESC
	   end_game(game, "Vous avez decider de quitter le jeu\n", 0);
	else if (keycode == 'w')
		move_player(game, 1, 0);
	else if (keycode == 's')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 0, 1);
	else if (keycode == 'a')
	{
		printf("Avant d'entrer dans la fonction\n");
		find_player(game);
		printf("player_x = %d\n", game->player_x);
		printf("player_y = %d\n", game->player_y);
		printf("hey\n");
		move_player(game, 0, -1);
	}
	return(0);
}

void	destroy_image(t_game *game)
{
	if (game->tex.player_image)
		mlx_destroy_image(game->mlx, game->tex.player_image);
	if (game->tex.collectibles_image)
		mlx_destroy_image(game->mlx, game->tex.collectibles_image);
	if (game->tex.wall_image)
		mlx_destroy_image(game->mlx, game->tex.wall_image);
	if (game->tex.exit_image)
		mlx_destroy_image(game->mlx, game->tex.exit_image);
	if (game->tex.floor_image)
		mlx_destroy_image(game->mlx, game->tex.floor_image);
}

int	end_game(t_game *game, char *msg, int exit_code)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		destroy_image(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	printf("%s", msg);
	exit(exit_code);
}