/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_bonus_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:05:21 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 11:27:37 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_img_nine(t_game *game);
void	ft_get_img_touched(t_game *game);
void	ft_get_img_heart(t_game *game);
void	ft_get_img_floor(t_game *game);
void	ft_get_img_collectibles(t_game *game);

void	ft_get_img_nine(t_game *game)
{
	int	w;
	int	h;

	game->tex_bonus.nine = mlx_xpm_file_to_image(game->mlx,
			"texture/nine.xpm", &w, &h);
	if (!game->tex_bonus.nine)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_touched(t_game *game)
{
	int	w;
	int	h;

	game->tex_bonus.touched = mlx_xpm_file_to_image(game->mlx,
			"texture/touched.xpm", &w, &h);
	if (!game->tex_bonus.touched)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_heart(t_game *game)
{
	int	w;
	int	h;

	game->tex_bonus.heart = mlx_xpm_file_to_image(game->mlx,
			"texture/heart.xpm", &w, &h);
	if (!game->tex_bonus.heart)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_floor(t_game *game)
{
	int	w;
	int	h;

	game->tex.floor_image = mlx_xpm_file_to_image(game->mlx,
			"texture/floor.xpm", &w, &h);
	if (!game->tex.floor_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_collectibles(t_game *game)
{
	int	w;
	int	h;

	game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx,
			"texture/collectibles.xpm", &w, &h);
	if (!game->tex.collectibles_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}
