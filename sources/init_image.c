/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 12:09:18 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 12:42:31 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_img_wall(t_game *game);
void	ft_get_img_floor(t_game *game);
void	ft_get_img_collectibles(t_game *game);
void	ft_get_img_exit(t_game *game);
void	ft_get_img_player(t_game *game);

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

void	ft_get_img_exit(t_game *game)
{
	int	w;
	int	h;

	game->tex.exit_image = mlx_xpm_file_to_image(game->mlx,
			"texture/exit.xpm", &w, &h);
	if (!game->tex.exit_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_player(t_game *game)
{
	int	w;
	int	h;

	game->tex.player_image = mlx_xpm_file_to_image(game->mlx,
			"texture/player.xpm", &w, &h);
	if (!game->tex.player_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void	ft_get_img_wall(t_game *game)
{
	int	w;
	int	h;

	game->tex.wall_image = mlx_xpm_file_to_image(game->mlx,
			"texture/wall.xpm", &w, &h);
	if (!game->tex.wall_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}
