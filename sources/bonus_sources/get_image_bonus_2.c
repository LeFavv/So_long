/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:04:43 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 01:08:36 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_get_img_four(t_game *game);
void    ft_get_img_five(t_game *game);
void    ft_get_img_six(t_game *game);
void    ft_get_img_seven(t_game *game);
void    ft_get_img_eight(t_game *game);


void    ft_get_img_four(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.four = mlx_xpm_file_to_image(game->mlx, 
		"texture/four.xpm", &w, &h);
    if (!game->tex_bonus.four)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_five(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.five = mlx_xpm_file_to_image(game->mlx, 
		"texture/five.xpm", &w, &h);
    if (!game->tex_bonus.five)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_six(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.six = mlx_xpm_file_to_image(game->mlx, 
		"texture/six.xpm", &w, &h);
    if (!game->tex_bonus.six)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_seven(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.seven = mlx_xpm_file_to_image(game->mlx, 
		"texture/seven.xpm", &w, &h);
    if (!game->tex_bonus.seven)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_eight(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.eight = mlx_xpm_file_to_image(game->mlx, 
		"texture/eight.xpm", &w, &h);
    if (!game->tex_bonus.eight)
		end_game(game, "Error\nXPM file invalide\n", 1);
}
