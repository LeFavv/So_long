/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/16 15:45:04 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(char **map);
int		check_rectangle(char **map);

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
	bot = nb_line(file);
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while(map[bot - 1][i])//creer une variable last pour bot-1 pour ameliorer visibilite
	{
		if (map[bot - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}
