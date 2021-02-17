/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:28:52 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:28:55 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static t_t	*init_tex(t_game *game)
{
	t_ray	*ray;

	ray = &game->ray;
	if (ray->side == 1)
	{
		if (ray->step.y > 0)
			return (&game->tex.NO);
		if (ray->step.y < 0)
			return (&game->tex.SO);
	}
	if (ray->side == 0)
	{
		if (ray->step.x > 0)
			return (&game->tex.WE);
		if (ray->step.x < 0)
			return (&game->tex.EA);
	}
	return (NULL);
}

static void	init_vars(t_game *game, t_tex_draw_vars *vars)
{
	t_ray				*ray;
	t_player			*player;

	ray = &game->ray;
	player = &game->player;
	if (ray->side == 0)
		vars->wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		vars->wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	vars->wall_x = 1 - (vars->wall_x - floor((vars->wall_x)));
	vars->tex_x = (int)(vars->wall_x * (double)(vars->tex->X));
	if (ray->side == 0 && ray->dir.x > 0)
		vars->tex_x = vars->tex->X - vars->tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		vars->tex_x = vars->tex->X - vars->tex_x - 1;
	vars->step = 1.0 * vars->tex->Y / ray->line_h;
	vars->tex_pos = (ray->draw_start - game->map.R[1] / 2 + ray->line_h / 2) *
		vars->step;
	vars->tex_num = game->map.map[ray->map.y][ray->map.x] - 1;
}

void		draw_skye(t_game *g, size_t i, int start, int end)
{
	while (start < end)
	{
		my_mlx_pixel_put(&g->img, i, start, g->map.C);
		++start;
	}
}

void		draw_ground(t_game *g, size_t i, int start, int end)
{
	while (start < end)
	{
		my_mlx_pixel_put(&g->img, i, start, g->map.F);
		++start;
	}
}

void		draw_tex(t_game *game, size_t i)
{
	t_tex_draw_vars		vars;
	t_ray				*ray;
	t_player			*player;
	int					y;

	ray = &game->ray;
	player = &game->player;
	vars.tex = init_tex(game);
	init_vars(game, &vars);
	y = ray->draw_start;
	draw_skye(game, i, 0, y);
	draw_ground(game, i, ray->draw_end, game->map.R[1]);
	while (y < ray->draw_end)
	{
		vars.tex_y = (int)vars.tex_pos & (64 - 1);
		vars.tex_pos += vars.step;
		vars.color = ((int*)vars.tex->img.addr)[64 * vars.tex_y + vars.tex_x];
		my_mlx_pixel_put(&game->img, i, y, vars.color);
		y++;
	}
}
