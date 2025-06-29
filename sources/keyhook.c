/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 03:08:20 by vafavard          #+#    #+#             */
/*   Updated: 2025/06/30 01:11:19 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_game *game)
{
	if (keycode == 57) //ESC
	   exit_game(game); // ou endgame fonction qui ferme la fenetre et free tout 
	else if (keycode == 'w')
		move_player(game, 1, 0);
	else if (keycode == 's')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, 0, -1);
	return(0);
}

//end_game
//free_map
//voir si victoire ou echec
//imprimer message
//exit(failure ou success ??)