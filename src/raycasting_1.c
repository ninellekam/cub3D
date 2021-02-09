/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:09:31 by yzena             #+#    #+#             */
/*   Updated: 2021/02/02 18:18:33 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// ------------------- ray ----------------------------------

int	init_ray_2(t_ray *ray, t_player *player)
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

void  ray_1(t_ray *ray, char **mymap)
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

void		ray_2(t_game *game)
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

void			ray(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	ray_1(ray, game->map.map);
	ray_2(game);
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

int			init_ray_1(t_game *game, size_t i)
{
	t_ray			  *ray;
	t_player		*player;
	t_map			  *map;

	ray = &game->ray;
	player = &game->player;
	map = &game->map;
	ray->camera_x = 2 * (map->R[0] - i) / (double)(map->R[0]) - 1;
	init_dir_map(ray, player, game);
	init_delta(ray);
	init_ray_2(ray, player);
	return (0);
}
