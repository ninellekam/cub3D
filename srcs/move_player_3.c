/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:24:41 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	crab_left(t_cub *cub)
{
	if (cub->map.map[(int)cub->player.pos.y]
			[(int)(cub->player.pos.x - cub->ray.plane.x * ROTATE)] == '0'
			|| is_player(cub->map.map[(int)cub->player.pos.y]
			[(int)(cub->player.pos.x - cub->ray.plane.x * ROTATE)]))
		cub->player.pos.x -= cub->ray.plane.x * ROTATE;
	if (cub->map.map[(int)(cub->player.pos.y - cub->ray.plane.y * ROTATE)]
			[(int)cub->player.pos.x] == '0' ||
			is_player(cub->map.map[(int)(cub->player.pos.y
			- cub->ray.plane.y * ROTATE)]
				[(int)cub->player.pos.x]))
		cub->player.pos.y -= cub->ray.plane.y * ROTATE;
}

void	crab_right(t_cub *cub)
{
	if (cub->map.map[(int)cub->player.pos.y]
			[(int)(cub->player.pos.x + cub->ray.plane.x * ROTATE)] == '0' ||
			is_player(cub->map.map[(int)cub->player.pos.y]
			[(int)(cub->player.pos.x + cub->ray.plane.x * ROTATE)]))
		cub->player.pos.x += cub->ray.plane.x * ROTATE;
	if (cub->map.map[(int)(cub->player.pos.y
		+ cub->ray.plane.y * ROTATE)]
		[(int)cub->player.pos.x] == '0'
		|| is_player(cub->map.map[(int)(cub->player.pos.y
		+ cub->ray.plane.y * ROTATE)]
		[(int)cub->player.pos.x]))
		cub->player.pos.y += cub->ray.plane.y * ROTATE;
}
