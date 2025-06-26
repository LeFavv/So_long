/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:49:36 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 19:02:00 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    find_player(t_game *game)
{
	int x;
	int y;

	y = 0;
	while(game->map[y])
	{
		x = 0;
		while(game->map[x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				return;
			}
			x++;
		}
		y++;
	}
}

void    move_player(t_game *game, int dy, int dx)
{
	int 	new_x;
	int 	new_y;
	char	next_tile = game->map[new_y][new_x];

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (next_tile == '1')
		return;
	else if (next_tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
	}
	else if (next_tile == 'E')
	{
		if (game->collectibles == 0)
			end_game(game);
		else
			return;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';	
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	printf("Moves : %d\n", game->moves);
	load_map(game->map);
}
