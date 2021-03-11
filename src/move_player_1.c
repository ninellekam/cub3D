/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:19 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 20:40:12 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_zero(t_button *but)
{
	return (but->w == 0 && but->s == 0 && but->a == 0
			&& but->d == 0 && but->left == 0
			&& but->right == 0);
}

void		rotate_left(t_game *game)
{
	double			old_dir_x;
	double			old_plane_x;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	plane = &(game->ray.plane);
	old_dir_x = dir->x;
	dir->x = dir->x * cos(-ROTSPEED) - dir->y * sin(-ROTSPEED);
	dir->y = old_dir_x * sin(-ROTSPEED) + dir->y * cos(-ROTSPEED);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(-ROTSPEED) - plane->y * sin(-ROTSPEED);
	plane->y = old_plane_x * sin(-ROTSPEED) + plane->y * cos(-ROTSPEED);
}

void		rotate_right(t_game *game)
{
	double			old_dir_x;
	double			old_plane_x;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(game->player.dir);
	pos = &(game->player.pos);
	plane = &(game->ray.plane);
	old_dir_x = dir->x;
	dir->x = dir->x * cos(ROTSPEED) - dir->y * sin(ROTSPEED);
	dir->y = old_dir_x * sin(ROTSPEED) + dir->y * cos(ROTSPEED);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(ROTSPEED) - plane->y * sin(ROTSPEED);
	plane->y = old_plane_x * sin(ROTSPEED) + plane->y * cos(ROTSPEED);
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
	if (game->button.a == 1)
		crab_left(game);
	if (game->button.d == 1)
		crab_right(game);
	if (game->button.left == 1)
		rotate_left(game);
	if (game->button.right == 1)
		rotate_right(game);
}
