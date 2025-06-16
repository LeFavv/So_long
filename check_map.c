/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/16 15:17:54 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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
