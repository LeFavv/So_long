/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:08:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/30 15:48:46 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 57) //ESC
	   end_game(game, "Vous avez decider de quitter le jeu\n", 0); // ou endgame fonction qui ferme la fenetre et free tout 
	else if (keycode == 'w')
		move_player(game, 1, 0);
	else if (keycode == 's')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, 0, -1);
	return(0);
}

//end_game
//free_map
//voir si victoire ou echec
//imprimer message
//exit(failure ou success ??)

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