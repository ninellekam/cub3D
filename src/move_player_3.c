/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 22:14:02 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/04 14:28:28 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	button_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->button.w = 1;
	if (keycode == KEY_S)
		game->button.s = 1;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		game->button.a = 1;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		game->button.d = 1;
	
	return (0);
}

int	button_unpressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->button.w = 0;
	if (keycode == KEY_S)
		game->button.s = 0;
	if (keycode == KEY_LEFT || keycode == KEY_A)
		game->button.a = 0;
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		game->button.d = 0;
	return (0);
}
