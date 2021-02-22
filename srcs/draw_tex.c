/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:28:52 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static t_t	*init_tex(t_cub *cub)
{
	t_ray	*ray;

	ray = &cub->ray;
	if (ray->side == 1)
	{
		if (ray->step.y > 0)
			return (&cub->tex.no);
		if (ray->step.y < 0)
			return (&cub->tex.so);
	}
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			return (&cub->tex.we);
		if (ray->step.x < 0)
			return (&cub->tex.ea);
	}
	return (NULL);
}

static void	iniiiiits(t_cub *cub, t_tex_draw_vars *vars)
{
	t_ray				*ray;
	t_player			*player;

	ray = &cub->ray;
	player = &cub->player;
	if (ray->side == 0)
		vars->wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		vars->wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	vars->wall_x = 1 - (vars->wall_x - floor((vars->wall_x)));
	vars->tex_x = (int)(vars->wall_x * (double)(vars->tex->width));
	if (ray->side == 0 && ray->dir.x > 0)
		vars->tex_x = vars->tex->width - vars->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		vars->tex_x = vars->tex->width - vars->tex_x - 1;
	vars->step = 1.0 * vars->tex->height / ray->line_h;
	vars->tex_pos = (ray->draw_start - cub->map.r[1] / 2 + ray->line_h / 2) *
		vars->step;
	vars->tex_num = cub->map.map[ray->map.y][ray->map.x] - 1;
}

void		draw_skye(t_cub *g, size_t i, int start, int end)
{
	while (start < end)
	{
		my_mlx_pixel_put(&g->img, i, start, g->map.c);
		++start;
	}
}

void		draw_ground(t_cub *g, size_t i, int start, int end)
{
	while (start < end)
	{
		my_mlx_pixel_put(&g->img, i, start, g->map.f);
		++start;
	}
}

void		draw_tex(t_cub *cub, size_t i)
{
	t_tex_draw_vars		vars;
	t_ray				*ray;
	t_player			*player;
	int					y;

	ray = &cub->ray;
	player = &cub->player;
	vars.tex = init_tex(cub);
	iniiiiits(cub, &vars);
	y = ray->draw_start;
	draw_skye(cub, i, 0, y);
	draw_ground(cub, i, ray->draw_end, cub->map.r[1]);
	while (y < ray->draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (64 - 1);
		vars.tex_pos += vars.step;
		vars.color = ((int*)vars.tex->img.addr)[64 * vars.tex_y + vars.tex_x];
		my_mlx_pixel_put(&cub->img, i, y, vars.color);
		y++;
	}
}
