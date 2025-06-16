/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:28:26 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/16 15:31:45 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//utils
int	ft_strlen(char *str);

//check map
int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(char **map);
int		check_rectangle(char **map);

#endif