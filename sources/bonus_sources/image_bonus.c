/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:37:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 01:13:15 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//ce fichier est obsolete mais garder comme backup au cas ou
//est pas remplace par 5 fichiers get_image_bonus_*.c + image_bonus_new_version.c

int    set_map_width_height(t_game *game);
void	init_image(t_game *game);

void	render_map(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.wall_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.floor_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.player_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.collectibles_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tex.exit_image, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'V')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.villain_image, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}	
}
//nouvelle version de render_map
void	render_map(t_game *game)
{
	int x;
	int y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while(game->map[y][x])
		{
			if (game->map[y][x] == '1')
				ft_put_image(game, 0, y, x);
			else if (game->map[y][x] == '0')
				ft_put_image(game, 1, y, x);
			else if (game->map[y][x] == 'P')
				ft_put_image(game, 2, y, x);
			else if (game->map[y][x] == 'C')
				ft_put_image(game, 3, y, x);
			else if (game->map[y][x] == 'E')
				ft_put_image(game, 4, y, x);
			else if (game->map[y][x] == 'V')
				ft_put_image(game, 5, y, x);
			x++;
		}
		y++;
	}	
}

void	ft_put_image(t_game *game, int index, int y, int x)
{
	if (index == 0)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.wall_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.floor_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 2)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.player_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 3)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex.collectibles_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 4)
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex.exit_image, x * TILE_SIZE, y * TILE_SIZE);
	else if (index == 5)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_bonus.villain_image, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map_bonus(t_game *game)
{
	if (game->nb_lives == 3)
	{
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex_bonus.heart, 1 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex_bonus.heart, 2 * TILE_SIZE, 0 * TILE_SIZE);
	}
	else if (game->nb_lives == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex_bonus.heart, 1 * TILE_SIZE, 0 * TILE_SIZE);	
	}
	else if (game->nb_lives == 1)
	{
		mlx_put_image_to_window(game->mlx,
			game->win, game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
	}
}

//deux fonctions de faite.. a implementer
void	render_map_number_move_bonus(t_game *game, char *str, int i, int j)
{
	i = 0;
	j = 5;
	game->map_width = ft_strlen(game->map[0]);
	while (str[i])
	{
		
		if (str[i] == '0')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.zero, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);				
		if (str[i] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.one, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '2')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.two, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '3')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.three, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '4')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.four, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '5')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.five, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '6')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.six, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '7')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.seven, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '8')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.eight, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		if (str[i] == '9')
			mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.nine, (game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
		i++;
		j--;
	}
}

//nouvelle fonction a tester
void	render_map_number_move_bonus(t_game *game, char *str, int i, int j)
{
	int index;

	i = 0;
	j = 5;
	game->map_width = ft_strlen(game->map[0]);
	while (str[i])
	{
		index = str[i] - '0';
		ft_put_image_number_z_to_f(game, index, j);
		i++;
		j--;
	}
}

void	ft_put_image_number_z_to_f(t_game *game, int index, int j)
{
	if (index == 0)
		mlx_put_image_to_window(game->mlx, game->win,game->tex_bonus.zero, 
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.one,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 2)		
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.two,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.three,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 4)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.four,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 5)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.five,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index > 5)
		ft_put_image_number_six_to_nine(game, index, j);
}

void	ft_put_image_number_six_to_nine(t_game *game, int index, int j)
{
	if (index == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.six,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 7)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.seven,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 8)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.eight,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);
	else if (index == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.nine,
			(game->map_width - j) * TILE_SIZE, game->map_height * TILE_SIZE);	
}

//faire un init_image bonus
void	init_image(t_game *game)
{
	// int	w;
	// int	h;
	
	// game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx, "texture/collectibles.xpm", &w, &h);//done
	// game->tex.exit_image = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &w, &h);//done
	// game->tex.floor_image = mlx_xpm_file_to_image(game->mlx, "texture/floor.xpm", &w, &h);//done
	// game->tex.player_image = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &w, &h);//done
	// game->tex.wall_image = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &w, &h);//done
	ft_get_img_collectibles(game);
	ft_get_img_exit(game);
	ft_get_img_floor(game);
	ft_get_img_player(game);
	ft_get_img_wall(game);
}

void	init_image_bonus(t_game *game)
{
	// int w;
	// int h;
	
	// game->tex_bonus.villain_image = mlx_xpm_file_to_image(game->mlx, "texture/villain.xpm", &w, &h);
	// game->tex_bonus.zero = mlx_xpm_file_to_image(game->mlx, "texture/zero.xpm", &w, &h);
	// game->tex_bonus.one = mlx_xpm_file_to_image(game->mlx, "texture/one.xpm", &w, &h);
	// game->tex_bonus.two = mlx_xpm_file_to_image(game->mlx, "texture/two.xpm", &w, &h);
	// game->tex_bonus.three = mlx_xpm_file_to_image(game->mlx, "texture/three.xpm", &w, &h);
	// game->tex_bonus.four = mlx_xpm_file_to_image(game->mlx, "texture/four.xpm", &w, &h);
	// game->tex_bonus.five = mlx_xpm_file_to_image(game->mlx, "texture/five.xpm", &w, &h);
	// game->tex_bonus.six = mlx_xpm_file_to_image(game->mlx, "texture/six.xpm", &w, &h);
	// game->tex_bonus.seven = mlx_xpm_file_to_image(game->mlx, "texture/seven.xpm", &w, &h);
	// game->tex_bonus.eight = mlx_xpm_file_to_image(game->mlx, "texture/eight.xpm", &w, &h);
	// game->tex_bonus.nine = mlx_xpm_file_to_image(game->mlx, "texture/nine.xpm", &w, &h);
	// game->tex_bonus.heart = mlx_xpm_file_to_image(game->mlx, "texture/heart.xpm", &w, &h);
	// game->tex_bonus.touched = mlx_xpm_file_to_image(game->mlx, "texture/touched.xpm", &w, &h);
		ft_get_img_zero(game);
		ft_get_img_villain(game);
		ft_get_img_one(game);
		ft_get_img_two(game);
		ft_get_img_three(game);
		ft_get_img_four(game);
		ft_get_img_five(game);
		ft_get_img_six(game);
		ft_get_img_seven(game);
		ft_get_img_eight(game);
		ft_get_img_nine(game);
		ft_get_img_touched(game);
		ft_get_img_heart(game);
}

void    ft_get_img_villain(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.villain_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/villain.xpm", &w, &h);
    if (!game->tex_bonus.villain_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_zero(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.zero = mlx_xpm_file_to_image(game->mlx, 
		"texture/zero.xpm", &w, &h);
    if (!game->tex_bonus.zero)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_one(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.one = mlx_xpm_file_to_image(game->mlx, 
		"texture/one.xpm", &w, &h);
    if (!game->tex_bonus.one)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_two(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.two = mlx_xpm_file_to_image(game->mlx, 
		"texture/two.xpm", &w, &h);
    if (!game->tex_bonus.two)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_three(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.three = mlx_xpm_file_to_image(game->mlx, 
		"texture/three.xpm", &w, &h);
    if (!game->tex_bonus.three)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_four(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.four = mlx_xpm_file_to_image(game->mlx, 
		"texture/four.xpm", &w, &h);
    if (!game->tex_bonus.four)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_five(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.five = mlx_xpm_file_to_image(game->mlx, 
		"texture/five.xpm", &w, &h);
    if (!game->tex_bonus.five)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_six(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.six = mlx_xpm_file_to_image(game->mlx, 
		"texture/six.xpm", &w, &h);
    if (!game->tex_bonus.six)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_seven(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.seven = mlx_xpm_file_to_image(game->mlx, 
		"texture/seven.xpm", &w, &h);
    if (!game->tex_bonus.seven)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_eight(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.eight = mlx_xpm_file_to_image(game->mlx, 
		"texture/eight.xpm", &w, &h);
    if (!game->tex_bonus.eight)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_nine(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.nine = mlx_xpm_file_to_image(game->mlx, 
		"texture/nine.xpm", &w, &h);
    if (!game->tex_bonus.nine)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_touched(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.touched = mlx_xpm_file_to_image(game->mlx, 
		"texture/touched.xpm", &w, &h);
    if (!game->tex_bonus.touched)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_heart(t_game *game)
{
	int w;
	int h;
	
    game->tex_bonus.heart = mlx_xpm_file_to_image(game->mlx, 
		"texture/heart.xpm", &w, &h);
    if (!game->tex_bonus.heart)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_floor(t_game *game)
{
	int w;
	int h;
	
    game->tex.floor_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/floor.xpm", &w, &h);
    if (!game->tex.floor_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
} 

void    ft_get_img_collectibles(t_game *game)
{
	int w;
	int h;
	
    game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/collectibles.xpm", &w, &h);
    if (!game->tex.collectibles_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
} 

void    ft_get_img_exit(t_game *game)
{
	int w;
	int h;
	
    game->tex.exit_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/exit.xpm", &w, &h);
    if (!game->tex.exit_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_player(t_game *game)
{
	int w;
	int h;
	
    game->tex.player_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/player.xpm", &w, &h);
    if (!game->tex.player_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}

void    ft_get_img_wall(t_game *game)
{
	int w;
	int h;
	
    game->tex.wall_image = mlx_xpm_file_to_image(game->mlx, 
		"texture/wall.xpm", &w, &h);
    if (!game->tex.wall_image)
		end_game(game, "Error\nXPM file invalide\n", 1);
}


int    set_map_width_height(t_game *game)
{
	int width;
	int	height;
	
	width = 0;
	height = 0;
	count_collectibles(game);
	while (game->map[0][width])
		width++;
	while(game->map[height])
		height++;
	if (height > MAX_HEIGHT || width > MAX_WIDTH)
		return (0);
	game->win_height = height * TILE_SIZE;
	game->win_width = width * TILE_SIZE;
	return (1);
}
