/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:03 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:30:05 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_side_hit(t_ray *ray, char **mymap)
{
	while (ray->hit == 0)
	{
		if (ray->side_d.x < ray->side_d.y)
		{
			ray->side_d.x += ray->delta.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->side_d.y += ray->delta.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (mymap[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

void	init_perp_wall_dist(t_game *game)
{
	t_ray		*ray;
	t_player	*player;

	ray = &game->ray;
	player = &game->player;
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map.x - player->pos.x +
				(1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - player->pos.y +
				(1 - ray->step.y) / 2) / ray->dir.y;
}
