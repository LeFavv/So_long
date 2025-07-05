/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/05 03:16:46 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(char **map);
int		check_rectangle(char **map);

int	nb_line(char *file)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	while ((line = get_next_line(fd)))
	{
		free(line);
		count++;
	}
	// line = get_next_line(fd);
	// while (line)
	// {
	// 	free(line);
	// 	count++;
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return (count);
}

char	**load_map(char *file)
{
	int		fd;
	int		lines;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	lines = nb_line(file);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while ((line = get_next_line(fd)))
	{
		map[i] = line;
		i++;
	}
	// line = get_next_line(fd);
	// while (line)
	// {
	// 	map[i] = line;
	// 	line = get_next_line(fd);
	// 	i++;
	// }
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
	remove_newline(map[i]);
	len = ft_strlen(map[i]);
	i++;
	while (map[i])
	{
		remove_newline(map[i]);
		if (len != (int)ft_strlen(map[i]))
			return (0);
		i++;
	}
	return (1);
}
