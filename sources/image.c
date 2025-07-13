/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:37:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 12:42:13 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_image(t_game *game);
int		set_map_width_height(t_game *game);
void	render_map(t_game *game);
void	ft_put_image(t_game *game, int index, int y, int x);

void	init_image(t_game *game)
{
	ft_get_img_floor(game);
	ft_get_img_collectibles(game);
	ft_get_img_exit(game);
	ft_get_img_player(game);
	ft_get_img_wall(game);
}

int	set_map_width_height(t_game *game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	count_collectibles(game);
	while (game->map[0][width])
		width++;
	while (game->map[height])
		height++;
	if (height > MAX_HEIGHT || width > MAX_WIDTH)
		return (0);
	game->win_height = height * TILE_SIZE;
	game->win_width = width * TILE_SIZE;
	return (1);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				ft_put_image(game, 0, y, x);
			else if (game->map[y][x] == '0')
				ft_put_image(game, 1, y, x);
			else if (game->map[y][x] == 'P')
				ft_put_image(game, 2, y, x);
			else if (game->map[y][x] == 'C')
				ft_put_image(game, 3, y, x);
			else if (game->map[y][x] == 'E')
				ft_put_image(game, 4, y, x);
			x++;
		}
		y++;
	}	
}

void	ft_put_image(t_game *game, int index, int y, int x)
{
	if (index == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.wall_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.floor_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.player_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.collectibles_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 4)
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex.exit_image, x * TILE_SIZE, y * TILE_SIZE);
}
