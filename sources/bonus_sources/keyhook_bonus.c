/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:08:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 13:59:34 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 65307) //ESC
	   end_game(game, "Vous avez decider de quitter le jeu\n", 0);
	else if (keycode == 's')
		move_player(game, 1, 0);
	else if (keycode == 'w')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, 0, -1);
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
	if (game->tex_bonus.touched)
		mlx_destroy_image(game->mlx, game->tex_bonus.touched);
}

void	destroy_image_bonus(t_game *game)
{
	if (game->tex_bonus.zero)
		mlx_destroy_image(game->mlx, game->tex_bonus.zero);
	if (game->tex_bonus.one)
		mlx_destroy_image(game->mlx, game->tex_bonus.one);
	if (game->tex_bonus.two)
		mlx_destroy_image(game->mlx, game->tex_bonus.two);
	if (game->tex_bonus.three)
		mlx_destroy_image(game->mlx, game->tex_bonus.three);
	if (game->tex_bonus.four)
		mlx_destroy_image(game->mlx, game->tex_bonus.four);
	if (game->tex_bonus.five)
		mlx_destroy_image(game->mlx, game->tex_bonus.five);
	if (game->tex_bonus.six)
		mlx_destroy_image(game->mlx, game->tex_bonus.six);
	if (game->tex_bonus.seven)
		mlx_destroy_image(game->mlx, game->tex_bonus.seven);
	if (game->tex_bonus.eight)
		mlx_destroy_image(game->mlx, game->tex_bonus.eight);
	if (game->tex_bonus.nine)
		mlx_destroy_image(game->mlx, game->tex_bonus.nine);
	if (game->tex_bonus.heart)
		mlx_destroy_image(game->mlx, game->tex_bonus.heart);
	if (game->tex_bonus.villain_image)
		mlx_destroy_image(game->mlx, game->tex_bonus.villain_image);
}
//detruire images bonus
int	end_game(t_game *game, char *msg, int exit_code)
{
	if (game)
	{
		if (game->map)
			free_map(game->map);
		destroy_image_bonus(game);
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
	printf("%s", msg);
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
		destroy_image_bonus(game);
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
	exit(0);
}

