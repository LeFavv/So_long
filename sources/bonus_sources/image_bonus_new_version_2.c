/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus_new_version_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:00:22 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/16 09:19:59 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_image_number_six_to_nine(t_game *game, int index, int j);
int		init_image(t_game *game);
void	init_image_bonus(t_game *game);
int		set_map_width_height(t_game *game);

void	ft_put_image_number_six_to_nine(t_game *game, int index, int j)
{
	if (index == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.six,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.seven,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 8)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.eight,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.nine,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
}

int	init_image(t_game *game)
{
	ft_get_img_collectibles(game);
	ft_get_img_exit(game);
	ft_get_img_floor(game);
	ft_get_img_player(game);
	ft_get_img_wall(game);
	init_image_bonus(game);
	return (1);
}

void	init_image_bonus(t_game *game)
{
	ft_get_img_zero(game);
	ft_get_img_villain(game);
	ft_get_img_one(game);
	ft_get_img_two(game);
	ft_get_img_three(game);
	ft_get_img_four(game);
	ft_get_img_five(game);
	ft_get_img_six(game);
	ft_get_img_seven(game);
	ft_get_img_eight(game);
	ft_get_img_nine(game);
	ft_get_img_touched(game);
	ft_get_img_heart(game);
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
