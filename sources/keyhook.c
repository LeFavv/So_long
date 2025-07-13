/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:08:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 12:58:28 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_hook(int keycode, t_game *game);
void	destroy_image(t_game *game);
int		end_game(t_game *game, char *msg, int exit_code);
int		exit_game(t_game *game);

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		end_game(game, "Vous avez decider de quitter le jeu\n", 0);
	else if (keycode == 's')
		move_player(game, 1, 0);
	else if (keycode == 'w')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, 0, -1);
	return (0);
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
		if (game->dup_map)
			free_dup_map(game->dup_map);
		free(game);
	}
	ft_ft_printf("%s", msg);
	exit(exit_code);
}

int	exit_game(t_game *game)
{
	if (game)
	{
		if (game->map)
		{
			free_map(game->map);
			game->map = NULL;
		}
		destroy_image(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		if (game->mlx)
			mlx_destroy_display(game->mlx);
		free(game->mlx);
		if (game->dup_map)
		{
			free_dup_map(game->dup_map);
			game->dup_map = NULL;
		}
		free(game);
	}
	exit (0);
}
