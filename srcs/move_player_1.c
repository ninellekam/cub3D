/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:19 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			is_zero(t_button *but)
{
	return (but->w == 0 && but->s == 0 && but->a == 0
			&& but->d == 0 && but->left == 0
			&& but->right == 0);
}

void		rotate_left(t_cub *cub)
{
	double			old_dir_x;
	double			old_plane_x;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(cub->player.dir);
	pos = &(cub->player.pos);
	plane = &(cub->ray.plane);
	old_dir_x = dir->x;
	dir->x = dir->x * cos(-ROTSPEED) - dir->y * sin(-ROTSPEED);
	dir->y = old_dir_x * sin(-ROTSPEED) + dir->y * cos(-ROTSPEED);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(-ROTSPEED) - plane->y * sin(-ROTSPEED);
	plane->y = old_plane_x * sin(-ROTSPEED) + plane->y * cos(-ROTSPEED);
}

void		rotate_right(t_cub *cub)
{
	double			old_dir_x;
	double			old_plane_x;
	t_double_vec	*pos;
	t_double_vec	*dir;
	t_double_vec	*plane;

	dir = &(cub->player.dir);
	pos = &(cub->player.pos);
	plane = &(cub->ray.plane);
	old_dir_x = dir->x;
	dir->x = dir->x * cos(ROTSPEED) - dir->y * sin(ROTSPEED);
	dir->y = old_dir_x * sin(ROTSPEED) + dir->y * cos(ROTSPEED);
	old_plane_x = plane->x;
	plane->x = plane->x * cos(ROTSPEED) - plane->y * sin(ROTSPEED);
	plane->y = old_plane_x * sin(ROTSPEED) + plane->y * cos(ROTSPEED);
}

void		move_player(t_cub *cub)
{
	t_player	*player;
	char		**map;

	player = &cub->player;
	map = cub->map.map;
	if (is_zero(&cub->button))
		return ;
	if (cub->button.w == 1)
		is_wall_front(cub);
	if (cub->button.s == 1)
		is_wall_backward(cub);
	if (cub->button.a == 1)
		crab_left(cub);
	if (cub->button.d == 1)
		crab_right(cub);
	if (cub->button.left == 1)
		rotate_left(cub);
	if (cub->button.right == 1)
		rotate_right(cub);
}

int			empty_lines(char *s)
{
	char	empty_status;

	if (s == NULL)
		return (GOOD);
	if (*s == '\0')
		return (GOOD);
	empty_status = BAD;
	while (*s != '\0')
	{
		if (ft_strchr("./CFRA", *s) != NULL)
			return (GOOD);
		s++;
	}
	return (empty_status);
}
