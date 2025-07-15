/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:52:02 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/15 10:05:55 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game_tex(t_game *game);
void	init_game_tex_bonus(t_game *game);

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->dup_map = NULL;
	game->mouv = NULL;
	game->nb_lives = 3;
	game->moves = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->win_width = 0;
	game->win_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->touched_timer = 0;
	game->nb_p = 0;
	game->nb_c = 0;
	game->nb_e = 0;
	init_game_tex(game);
	init_game_tex_bonus(game);
}

void	init_game_tex(t_game *game)
{
	game->tex.collectibles_image = NULL;
	game->tex.exit_image = NULL;
	game->tex.floor_image = NULL;
	game->tex.player_image = NULL;
	game->tex.wall_image = NULL;
}

void	init_game_tex_bonus(t_game *game)
{
	game->tex_bonus.zero = NULL;
	game->tex_bonus.one = NULL;
	game->tex_bonus.two = NULL;
	game->tex_bonus.three = NULL;
	game->tex_bonus.four = NULL;
	game->tex_bonus.five = NULL;
	game->tex_bonus.six = NULL;
	game->tex_bonus.seven = NULL;
	game->tex_bonus.eight = NULL;
	game->tex_bonus.nine = NULL;
	game->tex_bonus.heart = NULL;
	game->tex_bonus.touched = NULL;
	game->tex_bonus.villain_image = NULL;
}