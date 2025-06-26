/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:26:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 19:03:32 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	*game;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->win_width * TILE_SIZE , game->win_height * TILE_SIZE, "So Long");
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_loop(game->mlx);
}
