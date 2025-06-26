/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:28:26 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/26 17:46:15 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# define TILE_SIZE 64

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
    int         win_width;
    int         win_height;
	int			player_y;
	int			player_x;
	int			collectibles;
}	t_game;

//utils
int	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	**dup_map(char **map);

//check map + Map Errors
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
int		check_exit_number(char **map);
int		error_check(char **tab, char *file);

#endif