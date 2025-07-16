/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:12 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/16 12:16:45 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_sides(char **map, t_game *game);
int		check_name(char *file);
int		check_valide_cases(char **map, t_game *game);
void	flood_fill(t_game *game, int player_y, int player_x);
int		check_flood_fill(t_game *game);

int	check_sides(char **map, t_game *game)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(map[i]);
	while (i < game->map_height)
	{
		if (!(map[i][0] == '1' && map[i][len - 2] == '1'))
			return (0);
		i++;
	}
	return (1);
}

int	check_name(char *file)
{
	int	i;
	int	valide;

	valide = 0;
	i = 0;
	while (file[i] != '.')
		i++;
	i++;
	if (file[i] == 'b')
		valide += 1;
	if (file[i + 1] == 'e')
		valide += 1;
	if (file[i + 2] == 'r')
		valide += 1;
	if (file[i + 3] == '\0')
		valide += 1;
	if (valide == 4)
		return (1);
	else
		return (0);
}

int	check_valide_cases(char **map, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		remove_newline(map[i]);
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				game->nb_p += 1;
			else if (map[i][j] == 'E')
				game->nb_e += 1;
			else if (map[i][j] == 'C')
				game->nb_c += 1;
			else if (!(map[i][j] == '1' || map[i][j] == '0'))
				return (0);
			j++;
		}
	}
	if (game->nb_p == 1 && game->nb_e == 1 && game->nb_c >= 1)
		return (1);
	return (0);
}

void	flood_fill(t_game *game, int player_y, int player_x)
{
	find_player(game);
	if (game->dup_map[player_y][player_x] == '1'
	|| game->dup_map[player_y][player_x] == 'F')
		return ;
	if (game->dup_map[player_y][player_x] == 'E')
	{
		game->dup_map[player_y][player_x] = '1';
		return ;
	}
	game->dup_map[player_y][player_x] = 'F';
	flood_fill(game, player_y, player_x + 1);
	flood_fill(game, player_y, player_x - 1);
	flood_fill(game, player_y + 1, player_x);
	flood_fill(game, player_y - 1, player_x);
}

int	check_flood_fill(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->dup_map[y])
	{
		x = 0;
		while (game->dup_map[y][x])
		{
			if (game->dup_map[y][x] == 'E' || game->dup_map[y][x] == 'C')
			{
				free_dup_map(game->dup_map);
				game->dup_map = NULL;
				return (0);
			}
			x++;
		}
		y++;
	}
	free_dup_map(game->dup_map);
	game->dup_map = NULL;
	return (1);
}
