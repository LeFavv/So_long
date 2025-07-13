/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus_new_version.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:57:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/07/13 11:33:09 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game);
void	render_map_bonus(t_game *game);
void	ft_put_image(t_game *game, int index, int y, int x);
void	render_map_number_move_bonus(t_game *game, char *str, int i, int j);
void	ft_put_image_number_z_to_f(t_game *game, int index, int j);

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
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

void	render_map_number_move_bonus(t_game *game, char *str, int i, int j)
{
	int	index;

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
		mlx_put_image_to_window(game->mlx, game->win, game->tex_bonus.zero,
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
