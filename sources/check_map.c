/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 17:40:32 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(char **map);
int		check_rectangle(char **map);
int		check_top_bot(char **map, char *file);
int		check_sides(char **map);
int		check_name(char *file);
int		check_valide_cases(char **map);
void	flood_fill(char **dup_map, int player_y, int player_x);
int		check_flood_fill(char **dup_map);

int nb_line(char *file)
{
	int		fd;
	int		count;
	char	*line;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (line = get_next_line(fd))
	{
		free(line);
		count++;
	}
	close(fd);
	return (count);
}

char	**load_map(char *file)
{
	int		fd;
	int		lines;
	int		i = 0;
	char	**map;
	char	*line;
	
	lines = nb_line(file);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (line = get_next_line(fd))
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	free_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_dup_map(char **dup)
{
	int	i;
	
	i = 0;
	while (dup[i])
	{
		free(dup[i]);
		i++;
	}
	free(dup);
}

int	check_rectangle(char **map)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_top_bot(char **map, char *file)
{
	int	i;
	int	bot;
	
	i = 0;
	bot = nb_line(file) - 1;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(map[bot][i])
	{
		if (map[bot][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		check_sides(char **map)
{
	int	i;
	int	len;
	
	len = ft_strlen(map[i]);
	i = 0;
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
		while (map[i][j])
		{
			if (!(map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'C'))
				return (0);
			else if (map[i][j] == 'P')
				nb_p += 1;
			else if (map[i][j] == 'E')
				nb_e += 1;
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
			if (dup_map[y][x] != '1' && dup_map[y][x] != 'F')
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

int	error_check(char **tab, char *file)
{
	if (!check_sides(tab) || !check_top_bot(tab, file))
	{
		printf("Error\nThe map must contain only 1 (walls) on each sides\n");
		return (0);
	}
	else if (!check_rectangle(tab))
	{
		printf("Error\nThe map must be a rectangle\n");
		return (0);
	}
	else if (!check_name(tab))
	{
		printf("Error\nThe map must be a .ber file\n");
		return (0);
	}
	else if (!check_valide_cases(tab))
	{
		printf("Error\nYou must fill the map with 0, 1, P, C or E\n");
		return (0);
	}
	else if (!check_flood_fill(tab))
	{
		printf("Error\nThere is no path to collect all the coins and leave out\n");
		return (0);
	}
	else if (!check_exit_number(tab))
	{
		printf("Error\nYou need to have only one Exit in ur map\n");
		return (0);
	}
	else if (!load_map(file))
	{
		printf("Error\nThe map load failed\n");
		return (0);
	}
	return (1);
}

