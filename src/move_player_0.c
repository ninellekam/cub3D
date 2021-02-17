/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:14 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 21:56:35 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		is_wall_front(t_game *game)
{
	char			**m;
	t_double_vec	*pos;
	t_double_vec	*dir;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	m = game->map.map;
	if (game->button.w == 1)
	{
		if (game->map.map[(int)(pos->y + dir->y * ROTATE)]
			[(int)(pos->x)] == '0')
			pos->y += dir->y * ROTATE;
		if (game->map.map[(int)(pos->y)]
			[(int)(pos->x + dir->x * ROTATE)] == '0')
			pos->x += dir->x * ROTATE;
	}
}

void		is_wall_backward(t_game *game)
{
	char			**m;
	t_double_vec	*pos;
	t_double_vec	*dir;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	m = game->map.map;
	if (game->button.s == 1)
	{
		if (m[(int)(pos->y - dir->y * ROTATE)][(int)(pos->x)] == '0')
			pos->y -= dir->y * ROTATE;
		if (m[(int)(pos->y)][(int)(pos->x - dir->x * ROTATE)] == '0')
			pos->x -= dir->x * ROTATE;
	}
}

int			button_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		finish_game(game);
	if (keycode == KEY_W)
		game->button.w = 1;
	if (keycode == KEY_S)
		game->button.s = 1;
	if (keycode == KEY_A)
		game->button.a = 1;
	if (keycode == KEY_D)
		game->button.d = 1;
	if (keycode == KEY_LEFT)
		game->button.left = 1;
	if (keycode == KEY_RIGHT)
		game->button.right = 1;
	return (0);
}

int			button_unpressed(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->button.w = 0;
	if (keycode == KEY_S)
		game->button.s = 0;
	if (keycode == KEY_A)
		game->button.a = 0;
	if (keycode == KEY_D)
		game->button.d = 0;
	if (keycode == KEY_LEFT)
		game->button.left = 0;
	if (keycode == KEY_RIGHT)
		game->button.right = 0;
	return (0);
}
