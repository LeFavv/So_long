/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/16 15:58:24 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_exit_number(char **map);
int		error_check(char **tab, char *file, t_game *game);
void	remove_newline(char *line);
int		check_top_bot(char **map, char *file, t_game *game);

void	remove_newline(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	check_exit_number(char **map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	return (1);
}

int	check_top_bot(char **map, char *file, t_game *game)
{
	int	i;
	int	bot;

	i = 0;
	bot = nb_line(file) - 1;
	while (i < (int)ft_strlen(map[0]) - 1)
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[bot][i])
	{
		if (map[bot][i] != '1')
			return (0);
		i++;
	}
	game->map_height = bot;
	return (1);
}

int	error_check(char **tab, char *file, t_game *game)
{
	game->dup_map = dup_map(tab);
	find_player(game);
	if (!set_map_width_height(game))
		end_game(game, "Error\nMax Width 40 chars\nMax Height 21 chars\n", 1);
	else if (!check_top_bot(tab, file, game) || !check_sides(tab, game))
		end_game(game, "Error\nOnly 1 (walls) on each sides\n", 1);
	else if (!check_rectangle(tab))
		end_game(game, "Error\nThe map must be a rectangle\n", 1);
	else if (!check_valide_cases(tab, game))
		end_game(game, "Error\nMap= 0,1,only one P and E and one C min\n", 1);
	else if (!check_exit_number(tab))
		end_game(game, "Error\nYou need to have only one Exit in ur map\n", 1);
	else if (!game->map)
		end_game(game, "Error\nThe map load failed\n", 1);
	flood_fill(game, game->player_y, game->player_x);
	if (!check_flood_fill(game))
		end_game(game, "Error\nNo Valid path to success\n", 1);
	return (1);
}
