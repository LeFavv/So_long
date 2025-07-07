/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:49:36 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/07 09:46:05 by vafavard         ###   ########.fr       */
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
		while(game->map[y][x])
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
	int 	new_x = 0;
	int 	new_y = 0;
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	char	next_tile = game->map[new_y][new_x];

	find_player(game);
	if (next_tile == '1')
		return;
	else if (next_tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
		printf("nb de collectibles : %d\n", game->collectibles);
	}
	else if (next_tile == 'E')
	{
		if (game->collectibles == 0)
			end_game(game, "Felicitations vous avez reussi le jeu !\n", 1);
		else
			return;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';	
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	printf("Moves : %d\n", game->moves);
	render_map(game);
}
