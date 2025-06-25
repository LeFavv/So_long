/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:28:26 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/25 16:31:50 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_textures
{
	void	*player_image;
	void	*collectibles_image;
	void	*wall_image;
	void	*exit_image;
	void	*floor_image;
}	t_textures;


typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	tex;
	char		**map;
	int			moves;
	int			map_width;
	int			map_height;
	int			player_y;
	int			player_x;
	int			collectibles;
}	t_game;

//utils
int	ft_strlen(char *str);

//check map
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

#endif