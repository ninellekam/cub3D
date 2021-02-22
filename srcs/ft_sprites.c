/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:37:31 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_matrix(t_sprites *s, t_cub *g, int *order, int i)
{
	s->sprite_x = g->sprites.sprite[order[i]]->x - g->player.pos.x;
	s->sprite_y = g->sprites.sprite[order[i]]->y - g->player.pos.y;
	s->lyambda = 1.0 / (g->ray.plane.x * g->player.dir.y
		- g->player.dir.x * g->ray.plane.y);
	s->transformx = s->lyambda * (g->player.dir.y * s->sprite_x
		- g->player.dir.x * s->sprite_y);
	s->transformy = s->lyambda * (-g->ray.plane.y * s->sprite_x
		+ g->ray.plane.x * s->sprite_y);
	s->screenx = (int)((g->map.r[0] / 2) * (1 + s->transformx / s->transformy));
	s->s_h = abs((int)(g->map.r[1] / s->transformy));
}

void	ft_tex_sprite(t_cub *g, t_sprites *s)
{
	s->start_y = -s->s_h / 2 + g->map.r[1] / 2;
	if (s->start_y < 0)
		s->start_y = 0;
	s->end_y = s->s_h / 2 + g->map.r[1] / 2;
	if (s->end_y >= g->map.r[1])
		s->end_y = g->map.r[1] - 1;
	s->s_w = abs((int)(g->map.r[1] / s->transformy));
	s->start_x = -s->s_w / 2 + s->screenx;
	if (s->start_x < 0)
		s->start_x = 0;
	s->end_x = s->s_w / 2 + s->screenx;
	if (s->end_x >= g->map.r[0])
		s->end_x = g->map.r[0] - 1;
}

void	ft_final_sprite(t_cub *g, t_sprites *s)
{
	int				x;
	int				texy;
	unsigned int	color;

	while (g->sprites.hi < s->end_y)
	{
		x = (g->sprites.hi) * 256 - g->map.r[1] * 128 + s->s_h * 128;
		texy = ((x * g->sprites.tex.height) / s->s_h) / 256;
		color = ((unsigned int*)g->sprites.tex.img.addr)
		[(int)(g->sprites.tex.width * texy + g->sprites.texx)];
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&g->img, g->sprites.ok, g->sprites.hi, color);
		g->sprites.hi++;
	}
}

void	ft_draw_sprite(t_cub *g, t_sprites *s, double *buf)
{
	g->sprites.ok = s->start_x;
	while (g->sprites.ok < s->end_x)
	{
		g->sprites.hi = s->start_y;
		g->sprites.texx = (int)(256 * (g->sprites.ok - (-s->s_w / 2 +
			s->screenx)) * g->sprites.tex.width / s->s_w) / 256;
		if (s->transformy > 0 && g->sprites.ok > 0
			&& g->sprites.ok < g->map.r[0]
				&& s->transformy < buf[g->sprites.ok])
			ft_final_sprite(g, s);
		g->sprites.ok++;
	}
}

void	ft_sprite(t_cub *g, double *buf)
{
	t_sprites		s;
	size_t			i;
	double			dist[g->sprites.nums];
	int				order[g->sprites.nums];

	i = 0;
	while (i < g->sprites.nums)
	{
		order[i] = i;
		dist[i] = pow((g->player.pos.x - g->sprites.sprite[i]->x), 2);
		dist[i] += pow((g->player.pos.y - g->sprites.sprite[i]->y), 2);
		i++;
	}
	i = 0;
	quick_sort(order, dist, g->sprites.nums);
	while (i < g->sprites.nums)
	{
		ft_matrix(&s, g, order, i);
		ft_tex_sprite(g, &s);
		ft_draw_sprite(g, &s, buf);
		i++;
	}
}
