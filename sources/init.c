/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:52:02 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/07 09:54:37 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->map = NULL;
    game->dup_map = NULL;
    game->moves = 0;
    game->map_width = 0;
    game->map_height = 0;
    game->win_width = 0;
    game->win_height = 0;
    game->player_x = 0;
    game->player_y = 0;
    game->collectibles = 0;
}
