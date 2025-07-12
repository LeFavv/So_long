/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:04:02 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 01:09:26 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_get_img_villain(t_game *game);
void    ft_get_img_zero(t_game *game);
void    ft_get_img_one(t_game *game);
void    ft_get_img_two(t_game *game);
void    ft_get_img_three(t_game *game);


void    ft_get_img_villain(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.villain_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/villain.xpm", &w, &h);
    if (!game->tex_bonus.villain_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_zero(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.zero = mlx_xpm_file_to_image(game->mlx, 
		"texture/zero.xpm", &w, &h);
    if (!game->tex_bonus.zero)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_one(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.one = mlx_xpm_file_to_image(game->mlx, 
		"texture/one.xpm", &w, &h);
    if (!game->tex_bonus.one)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_two(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.two = mlx_xpm_file_to_image(game->mlx, 
		"texture/two.xpm", &w, &h);
    if (!game->tex_bonus.two)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_three(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.three = mlx_xpm_file_to_image(game->mlx, 
		"texture/three.xpm", &w, &h);
    if (!game->tex_bonus.three)
		end_game(game, "Error\nXPM file invalide\n", 1);
}
