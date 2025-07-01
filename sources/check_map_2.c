/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:31:12 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/01 15:59:53 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_sides(char **map);
int		check_name(char *file);
int		check_valide_cases(char **map);
void	flood_fill(char **dup_map, int player_y, int player_x);
int		check_flood_fill(char **dup_map);

int		check_sides(char **map)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(map[i]);
	while(map[i])
	{
		if (map[i][0] != '1' && map[i][len] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_name(char *file)
{
	int i;
	int valide;
	
	valide = 0;
	i = 0;
	while (file[i])
		i++;
	if (file[i - 1] == 'r')
		valide += 1;
	if(file[i - 2] == 'e')
		valide += 1;
	if (file[i - 3] == 'b')
		valide += 1;
	if (file[i - 4] == '.')
		valide += 1;
	if (valide == 4)
		return (1);
	else
		return (0);
}

int		check_valide_cases(char **map)
{
	int	i;
	int	j;
	int nb_p;
	int	nb_e;
	
	i = 0;
	nb_e = 0;
	nb_p = 0;
	while (map[i])
	{
		j = 0;
		remove_newline(map[i]);
		while (map[i][j])
		{
			
			if (map[i][j] == 'P')
				nb_p += 1;
				
			else if (map[i][j] == 'E')
				nb_e += 1;
			else if (!(map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'C'))
				return (0);	
				
			j++;
		}
		i++;
	}
	if (nb_p != 1 || nb_e != 1)
			return (0);
		return (1);
}

void	flood_fill(char **dup_map, int player_y, int player_x)
{
	if (dup_map[player_y][player_x] == '1' || dup_map[player_y][player_x] == 'F')
		return;
	dup_map[player_y][player_x] = 'F';
	flood_fill(dup_map, player_y, player_x + 1);
	flood_fill(dup_map, player_y , player_x - 1);
	flood_fill(dup_map, player_y + 1, player_x);
	flood_fill(dup_map, player_y - 1, player_x);
}

int check_flood_fill(char **dup_map)
{
	int	x;
	int	y;

	y = 0;
	while (dup_map[y])
	{
		x = 0;
		while (dup_map[y][x])
		{
			if (dup_map[y][x] == 'E' || dup_map[y][x] == 'C')
			{
				free_dup_map(dup_map);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_dup_map(dup_map);
	return (1);
}
