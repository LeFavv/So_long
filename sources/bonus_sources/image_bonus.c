/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:37:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 03:28:40 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    set_map_width_height(t_game *game);
void	init_image(t_game *game);

void	render_map(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{//possible de rajouter une fontion ici pour mettre plus d'images (perso blesse et les nombres ?)
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.wall_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.floor_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.player_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectibles_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.exit_image, x * TILE_SIZE, y * TILE_SIZE);
			//render_map_bonus
			else if (game->map[y][x] == 'V')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.villain_image, x * TILE_SIZE, y * TILE_SIZE);				
			x++;
		}
		y++;
	}	
}

//mettre les coeurs full
void	render_map_bonus(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart_full, 0 * TILE_SIZE, 0 * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart_full, 1 * TILE_SIZE, 0 * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart_full, 2 * TILE_SIZE, 0 * TILE_SIZE);


}

//faire un init_image bonus
void	init_image(t_game *game)
{
	int	w;
	int	h;
	
	game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx, "texture/collectibles.xpm", &w, &h);
	game->tex.exit_image = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &w, &h);
	game->tex.floor_image = mlx_xpm_file_to_image(game->mlx, "texture/floor.xpm", &w, &h);
	game->tex.player_image = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &w, &h);
	game->tex.wall_image = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &w, &h);
	game->tex_bonus.villain_image = mlx_xpm_file_to_image(game->mlx, "texture/villain.xpm", &w, &h);
	//villain a mettre dans bonus
}

int    set_map_width_height(t_game *game)
{
	int width;
	int	height;
	
	width = 0;
	height = 0;
	count_collectibles(game);
	while (game->map[0][width])
		width++;
	while(game->map[height])
		height++;
	if (height > MAX_HEIGHT || width > MAX_WIDTH)
		return (0);
	game->win_height = height * TILE_SIZE;
	game->win_width = width * TILE_SIZE;
	return (1);
}
