/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:58 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:30:00 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		init_ray_1(t_ray *ray, t_player *player)
{
	t_double_vec *pos;

	pos = &player->pos;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_d.x = (pos->x - ray->map.x) * ray->delta.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_d.x = (ray->map.x + 1.0 - pos->x) * ray->delta.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_d.y = (pos->y - ray->map.y) * ray->delta.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_d.y = (ray->map.y + 1.0 - pos->y) * ray->delta.y;
	}
	ray->hit = 0;
	return (0);
}

void	ray(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	init_side_hit(ray, game->map.map);
	init_perp_wall_dist(game);
	ray->line_h = (int)(game->map.R[1] / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_h) / 2 + game->map.R[1] / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_h / 2 + game->map.R[1] / 2;
	if (ray->draw_end >= game->map.R[1])
		ray->draw_end = game->map.R[1];
}

void	init_dir_map(t_ray *ray, t_player *player, t_game *game)
{
	ray->dir.x = player->dir.x + ray->plane.x * ray->camera_x;
	ray->dir.y = player->dir.y + ray->plane.y * ray->camera_x;
	ray->map.x = (int)game->player.pos.x;
	ray->map.y = (int)game->player.pos.y;
}

void	init_delta(t_ray *ray)
{
	ray->delta.x = fabs(1 / ray->dir.x);
	ray->delta.y = fabs(1 / ray->dir.y);
}

int		init_ray_0(t_game *game, size_t i)
{
	t_ray			*ray;
	t_player		*player;
	t_map			*map;

	ray = &game->ray;
	player = &game->player;
	map = &game->map;
	ray->camera_x = 2 * i / (double)(map->R[0]) - 1;
	init_dir_map(ray, player, game);
	init_delta(ray);
	init_ray_1(ray, player);
	return (0);
}
