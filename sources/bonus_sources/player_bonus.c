/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:49:36 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/12 22:29:09 by vafavard         ###   ########.fr       */
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

int	update(void *param)
{
	t_game *game = (t_game *)param;
	if (game->touched_timer > 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_bonus.touched, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
		game->touched_timer--;
	}
		else
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.player_image, game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	return (0);	
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
	else if (next_tile == 'V')
	{
		game->nb_lives -= 1;
		printf("\033[31mAIE ! Il ne te reste que %d vie\n\033[0m\n", game->nb_lives);
		game->touched_timer = 6000;
		if (game->nb_lives == 0)
			end_game(game, "\033[31mLOOSER ! T'AS PERDU\n\033[0m\n", 1);
		return (0);
	}
	else if (next_tile == 'E')
	{
		if (game->collectibles == 0)
			end_game(game, "\033[32mFelicitations vous avez reussi le jeu !\033[0m\n", 1);
		else
			return (0);
	}
	return (1);
}

void    move_player(t_game *game, int dy, int dx)
{
	int 	new_x = 0;
	int 	new_y = 0;
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	char	next_tile = game->map[new_y][new_x];

	find_player(game);
	if (!move_player_bis(game, new_y, new_x, next_tile))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';	
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	game->mouv = ft_itoa_bonus(game->moves);
	printf("Moves : %d\n", game->moves);
	render_map(game);
	render_map_bonus(game);
	render_map_number_move_bonus(game, game->mouv, new_x, new_y);
	free(game->mouv);
}

// void    move_player(t_game *game, int dy, int dx)
// {
// 	int 	new_x = 0;
// 	int 	new_y = 0;
// 	new_x = game->player_x + dx;
// 	new_y = game->player_y + dy;
// 	char	next_tile = game->map[new_y][new_x];

// 	find_player(game);
// 	if (next_tile == '1')
// 		return;
// 	else if (next_tile == 'C')
// 	{
// 		game->map[new_y][new_x] = '0';
// 		game->collectibles--;
// 		printf("nb de collectibles : %d\n", game->collectibles);
// 	}
// 	else if (next_tile == 'V')
// 	{
// 		game->nb_lives -= 1;
// 		printf("\033[31mAIE ! Il ne te reste que %d vie\nAtttention a toi mon gourmand\033[0m\n", game->nb_lives);
// 		game->touched_timer = 6000;
// 		if (game->nb_lives == 0)
// 			end_game(game, "\033[31mLOOSER ! T'AS PERDU\n\033[0m\n", 1);
// 		return;
// 	}
// 	else if (next_tile == 'E')
// 	{
// 		if (game->collectibles == 0)
// 			end_game(game, "\033[32mFelicitations vous avez reussi le jeu !\033[0m\n", 1);
// 		else
// 			return;
// 	}
// 	game->map[game->player_y][game->player_x] = '0';
// 	game->map[new_y][new_x] = 'P';	
// 	game->player_x = new_x;
// 	game->player_y = new_y;
// 	game->moves++;
// 	game->mouv = ft_itoa_bonus(game->moves);
// 	printf("Moves : %d\n", game->moves);
// 	render_map(game);
// 	render_map_bonus(game);
// 	render_map_number_move_bonus(game, game->mouv, new_x, new_y);
// 	free(game->mouv);
// }
