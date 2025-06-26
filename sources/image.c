/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:37:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 04:10:58 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    set_map_width_height(t_game *game);
void	init_image(t_game *game);

void	init_image(t_game *game)
{
	int	w;
	int	h;
	
	game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx, "texture/collectibles.xpm", &w, &h);
	game->tex.exit_image = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &w, &h);
	game->tex.floor_image = mlx_xpm_file_to_image(game->mlx, "texture/floor.xpm", &w, &h);
	game->tex.player_image = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &w, &h);
	game->tex.wall_image = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &w, &h);
}

void    set_map_width_height(t_game *game)
{
	int width;
	int	height;
	
	width = 0;
	height = 0;
	while (game->map[0][width])
		width++;
	game->map_width = width;
	while(game->map[height])
		height++;
	game->map_height = height;
	game->win_height = height * TILE_SIZE;
	game->win_width = width * TILE_SIZE;
}
