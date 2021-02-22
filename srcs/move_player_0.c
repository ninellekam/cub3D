/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:14 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		is_wall_front(t_cub *cub)
{
	char			**m;
	t_double_vec	*pos;
	t_double_vec	*dir;

	dir = &(cub->player.dir);
	pos = &(cub->player.pos);
	m = cub->map.map;
	if (cub->button.w == 1)
	{
		if (cub->map.map[(int)(pos->y + dir->y * ROTATE)]
			[(int)(pos->x)] == '0')
			pos->y += dir->y * ROTATE;
		if (cub->map.map[(int)(pos->y)]
			[(int)(pos->x + dir->x * ROTATE)] == '0')
			pos->x += dir->x * ROTATE;
	}
}

void		is_wall_backward(t_cub *cub)
{
	char			**m;
	t_double_vec	*pos;
	t_double_vec	*dir;

	dir = &(cub->player.dir);
	pos = &(cub->player.pos);
	m = cub->map.map;
	if (cub->button.s == 1)
	{
		if (m[(int)(pos->y - dir->y * ROTATE)][(int)(pos->x)] == '0')
			pos->y -= dir->y * ROTATE;
		if (m[(int)(pos->y)][(int)(pos->x - dir->x * ROTATE)] == '0')
			pos->x -= dir->x * ROTATE;
	}
}

int			button_pressed(int keycode, t_cub *cub)
{
	if (keycode == KEY_ESC)
		finish_cub(cub);
	if (keycode == KEY_W)
		cub->button.w = 1;
	if (keycode == KEY_S)
		cub->button.s = 1;
	if (keycode == KEY_A)
		cub->button.a = 1;
	if (keycode == KEY_D)
		cub->button.d = 1;
	if (keycode == KEY_LEFT)
		cub->button.left = 1;
	if (keycode == KEY_RIGHT)
		cub->button.right = 1;
	return (0);
}

int			button_unpressed(int keycode, t_cub *cub)
{
	if (keycode == KEY_W)
		cub->button.w = 0;
	if (keycode == KEY_S)
		cub->button.s = 0;
	if (keycode == KEY_A)
		cub->button.a = 0;
	if (keycode == KEY_D)
		cub->button.d = 0;
	if (keycode == KEY_LEFT)
		cub->button.left = 0;
	if (keycode == KEY_RIGHT)
		cub->button.right = 0;
	return (0);
}
