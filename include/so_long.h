/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:28:26 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 04:30:56 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# define TILE_SIZE 64
# define MAX_WIDTH 40
# define MAX_HEIGHT 21


typedef struct s_textures
{
	void	*player_image;
	void	*collectibles_image;
	void	*wall_image;
	void	*exit_image;
	void	*floor_image;
//	void	*villain_image;
}	t_textures;

typedef struct s_textures_bonus
{
	void	*villain_image;
	void	*hurt_player;
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	void	*heart_full;
	void	*heart_empty;
} t_textures_bonus;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	tex;
	t_textures_bonus tex_bonus;
	char		**map;
	char		**dup_map;
	int			nb_lives;
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
char	**dup_map(char **map);

//collectibles
void count_collectibles(t_game *game);

//image
void	render_map(t_game *game);
void	init_image(t_game *game);
int    set_map_width_height(t_game *game);

//hook
int key_hook(int keycode, t_game *game);

//player
void    find_player(t_game *game);
void    move_player(t_game *game, int dy, int dx);

//free
void	free_dup_map(char **dup);
void	free_map(char **map);

//check map + Map Errors
int		nb_line(char *file);
char	**load_map(char *file);
void	free_map(char **map);
int		check_rectangle(char **map);
int		check_top_bot(char **map, char *file);
int		check_sides(char **map);
int		check_name(char *file);
int		check_valide_cases(char **map);
void	flood_fill(t_game *game, int player_y, int player_x);
int		check_flood_fill(t_game *game);
int		check_exit_number(char **map);
int		error_check(char **tab, char *file, t_game *game);
int		check_command_line_params(int argc, char **argv);
void	remove_newline(char *line);


//end
void	destroy_image(t_game *game);
int	end_game(t_game *game, char *msg, int exit_code);

int	exit_game(t_game *game);

void init_game(t_game *game);

#endif