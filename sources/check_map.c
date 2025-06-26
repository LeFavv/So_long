/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 13:36:43 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(t_game *game);
int		check_rectangle(t_game *game);
int		check_top_bot(t_game *game, char *file);
int		check_sides(t_game *game);
int		check_name(char *file);
int		check_valide_cases(t_game *game);
void	flood_fill(char **dup_map, int player_y, int player_x);
int		check_flood_fill(char **dup_map);

//message d'erreur si pas de chemin valide
//Compter de na'voir qu'une sortie

//a faire : gerer les messages d'erreurs explicites

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

void	free_map(t_game *game)
{
	int	i;
	
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
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

int	check_rectangle(t_game *game)
{
	int	i;
	int	len;
	
	i = 0;
	len = ft_strlen(game->map[i]);
	while (game->map[i])
	{
		if (len != ft_strlen(game->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_top_bot(t_game *game, char *file)
{
	int	i;
	int	bot;
	
	i = 0;
	bot = nb_line(file) - 1;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(game->map[bot][i])
	{
		if (game->map[bot][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		check_sides(t_game *game)
{
	int	i;
	int	len;
	
	len = ft_strlen(game->map[i]);
	i = 0;
	while(game->map[i])
	{
		if (game->map[i][0] != '1' && game->map[i][len] != '1')
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

int		check_valide_cases(t_game *game)
{
	int	i;
	int	j;
	int nb_p;
	int	nb_e;
	
	i = 0;
	nb_e = 0;
	nb_p = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!(game->map[i][j] == '1' || game->map[i][j] == '0' || game->map[i][j] == 'C'))
				return (0);
			else if (game->map[i][j] == 'P')
				nb_p += 1;
			else if (game->map[i][j] == 'E')
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

int	error_check(char **tab)
{
	if (!check_sides(tab) || !check_top_bot(tab))
	{
		printf("Error\nThe map must contain only 1 (walls) on each sides\n");
		return (0);
	}
	if (!check_rectangle(tab))
	{
		printf("Error\nThe map must be a rectangle\n");
		return (0);
	}
	if (!check_name(tab))
	{
		printf("Error\nThe map must be a .ber file\n");
		return (0);
	}
	if (!check_valide_cases(tab))
	{
		printf("Error\nYou must fill the map with 0, 1, P, C or E\n");
		return (0);
	}
	if (!check_flood_fill(tab))
	{
		printf("Error\nThere is no path to collect all the coins and leave out\n");
		return (0);
	}
	if (!check_exit_number(tab))
	{
		printf("Error\nYou need to have only one Exit in ur map\n");
		return (0);
	}
	return (1);

}
