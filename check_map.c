/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:43:25 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/16 15:07:10 by vafavard         ###   ########.fr       */
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

