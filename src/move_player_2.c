/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:47:54 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/04 14:30:39 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_zero(t_button *but)
{
	return (but->w == 0 && but->s == 0 && but->a == 0 && but->d == 0);
}

void	is_wall_front(t_game *game)
{
	char **m;
	t_double_vec *pos;
	t_double_vec *dir;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	m = game->map.map;
	if (game->button.w == 1)
	{
		// printf("%c\n", game->map.map[(int)(pos->y + dir->y * ROTATE)][(int)(pos->x)]);
		if(game->map.map[(int)(pos->y + dir->y * ROTATE)][(int)(pos->x)] == '0')
			pos->y += dir->y * ROTATE;
		if(game->map.map[(int)(pos->y)][(int)(pos->x + dir->x * ROTATE)] == '0')
			pos->x += dir->x * ROTATE;
	}
}

void	is_wall_backward(t_game *game)
{
	char **m;
	t_double_vec *pos;
	t_double_vec *dir;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	m = game->map.map;
	if (game->button.s == 1)
	{
		if (m[(int)(pos->y - dir->y * ROTATE)][(int)(pos->x)] == '0')
			pos->y -= dir->y * ROTATE;
		if(m[(int)(pos->y)][(int)(pos->x - dir->x * ROTATE)] == '0')
			pos->x -= dir->x * ROTATE;
	}
}

void	rotate_right(t_game *game)
{
	double			oldDirX;
	double			oldPlaneX;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	plane = &(game->ray.plane);
	oldDirX = dir->x;
	dir->x = dir->x * cos(-ROTSPEED) - dir->y * sin(-ROTSPEED);
	dir->y = oldDirX * sin(-ROTSPEED) + dir->y * cos(-ROTSPEED);
	oldPlaneX = plane->x;
	plane->x = plane->x * cos(-ROTSPEED) - plane->y * sin(-ROTSPEED);
	plane->y = oldPlaneX * sin(-ROTSPEED) + plane->y * cos(-ROTSPEED);
}

void	rotate_left(t_game *game)
{
		double			oldDirX;
	double			oldPlaneX;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	plane = &(game->ray.plane);
	oldDirX = dir->x;
	dir->x = dir->x * cos(ROTSPEED) - dir->y * sin(ROTSPEED);
	dir->y = oldDirX * sin(ROTSPEED) + dir->y * cos(ROTSPEED);
	oldPlaneX = plane->x;
	plane->x = plane->x * cos(ROTSPEED) - plane->y * sin(ROTSPEED);
	plane->y = oldPlaneX * sin(ROTSPEED) + plane->y * cos(ROTSPEED);
}

void		move_player(t_game *game)
{
	t_player	*player;
	char		**map;

	player = &game->player;
	map = game->map.map;
	if (is_zero(&game->button))
		return ;
	if (game->button.w == 1)
		is_wall_front(game);
	if (game->button.s == 1)
		is_wall_backward(game);
	if (game->button.d == 1)
		rotate_left(game);
	if (game->button.a == 1)
		rotate_right(game);
}
