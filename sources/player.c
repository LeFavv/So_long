/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:49:36 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 12:44:38 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	move_player_bis(t_game *game, int new_y, int new_x, char next_tile)
{
	if (next_tile == '1')
		return (0);
	else if (next_tile == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
		printf("nb de collectibles : %d\n", game->collectibles);
	}
	else if (next_tile == 'E')
	{
		if (game->collectibles == 0)
			end_game(game, "\033[32mFelicitations Champion(ne) !\033[0m\n", 1);
		else
			return (0);
	}
	return (1);
}

void	move_player(t_game *game, int dy, int dx)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	next_tile = game->map[new_y][new_x];
	find_player(game);
	if (!move_player_bis(game, new_y, new_x, next_tile))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	printf("Moves : %d\n", game->moves);
	render_map(game);
}
