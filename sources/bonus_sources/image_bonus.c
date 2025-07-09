/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:37:08 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/09 11:57:18 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		{//possible de rajouter une fontion ici pour mettre plus d'images (perso blesse et les nombres ?)
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
			//render_map_bonus
			else if (game->map[y][x] == 'V')
				mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.villain_image, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}	
}

//mettre les coeurs full
void	render_map_bonus(t_game *game)
{
	if (game->nb_lives == 3)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 1 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 2 * TILE_SIZE, 0 * TILE_SIZE);
	}
	else if (game->nb_lives == 2)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 1 * TILE_SIZE, 0 * TILE_SIZE);		
	}
	else if (game->nb_lives == 1)
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.heart, 0 * TILE_SIZE, 0 * TILE_SIZE);
}

//nouvelle fonction (lignes trop longues et limite de 25 lignes donc a voir...)
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

//faire un init_image bonus
void	init_image(t_game *game)
{
	int	w;
	int	h;
	
	game->tex.collectibles_image = mlx_xpm_file_to_image(game->mlx, "texture/collectibles.xpm", &w, &h);
	game->tex.exit_image = mlx_xpm_file_to_image(game->mlx, "texture/exit.xpm", &w, &h);
	game->tex.floor_image = mlx_xpm_file_to_image(game->mlx, "texture/floor.xpm", &w, &h);
	game->tex.player_image = mlx_xpm_file_to_image(game->mlx, "texture/player.xpm", &w, &h);
	game->tex.wall_image = mlx_xpm_file_to_image(game->mlx, "texture/wall.xpm", &w, &h);
}

void	init_image_bonus(t_game *game)
{
	int w;
	int h;
	
	game->tex_bonus.villain_image = mlx_xpm_file_to_image(game->mlx, "texture/villain.xpm", &w, &h);
	game->tex_bonus.zero = mlx_xpm_file_to_image(game->mlx, "texture/zero.xpm", &w, &h);
	game->tex_bonus.one = mlx_xpm_file_to_image(game->mlx, "texture/one.xpm", &w, &h);
	game->tex_bonus.two = mlx_xpm_file_to_image(game->mlx, "texture/two.xpm", &w, &h);
	game->tex_bonus.three = mlx_xpm_file_to_image(game->mlx, "texture/three.xpm", &w, &h);
	game->tex_bonus.four = mlx_xpm_file_to_image(game->mlx, "texture/four.xpm", &w, &h);
	game->tex_bonus.five = mlx_xpm_file_to_image(game->mlx, "texture/five.xpm", &w, &h);
	game->tex_bonus.six = mlx_xpm_file_to_image(game->mlx, "texture/six.xpm", &w, &h);
	game->tex_bonus.seven = mlx_xpm_file_to_image(game->mlx, "texture/seven.xpm", &w, &h);
	game->tex_bonus.eight = mlx_xpm_file_to_image(game->mlx, "texture/eight.xpm", &w, &h);
	game->tex_bonus.nine = mlx_xpm_file_to_image(game->mlx, "texture/nine.xpm", &w, &h);
	game->tex_bonus.heart = mlx_xpm_file_to_image(game->mlx, "texture/heart.xpm", &w, &h);
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
