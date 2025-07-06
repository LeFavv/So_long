/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:15 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/06 18:33:05 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_exit_number(char **map);
int		error_check(char **tab, char *file, t_game *game);
void	remove_newline(char *line);
int		check_top_bot(char **map, char *file);

void	remove_newline(char *line)
{
	int len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	check_exit_number(char **map)
{
	int	x;
	int	y;
	int count;

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
int	check_top_bot(char **map, char *file)
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
	return (1);
}

int	error_check(char **tab, char *file, t_game *game)
{
    game->dup_map = dup_map(tab);
    int x;
	find_player(game);
    flood_fill(game, game->player_y, game->player_x); 
        x = 0;
	//mettre end_game au lieu des printf a chaque fois
	if (!check_sides(tab) || !check_top_bot(tab, file))
	{
		printf("top bot %d\n", check_top_bot(tab, file));
		printf("Error\nThe map must contain only 1 (walls) on each sides\n");
		exit_game(game);
		return (0);
	}
	else if (!check_rectangle(tab))
	{
		printf("Error\nThe map must be a rectangle\n");
		exit_game(game);
		return (0);
	}
	
	else if (!check_valide_cases(tab))
	{
		printf("Error\nYou must fill the map with 0, 1, P, C or E\n");
		exit_game(game);		
		return (0);
	}

	else if (!check_flood_fill(game))
	{
		printf("Error\nThere is no path to collect all the coins and leave out\n");
		exit_game(game);		
		return (0);
	}
	else if (!check_exit_number(tab))
	{
		printf("Error\nYou need to have only one Exit in ur map\n");
		exit_game(game);		
		return (0);
	}
	else if (!load_map(file))
	{
		printf("Error\nThe map load failed\n");
		exit_game(game);		
		return (0);
	}
	else if (!set_map_width_height(game))
	{
		printf("Error\nThe map do not respect the size rules : Max Width = 40 characteres Max Height = 21 characters\n");
		exit_game(game);		
		return (0);
	}
	return (1);
}
