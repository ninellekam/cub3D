/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:05:13 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/10 13:00:48 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "game.h"

// void	ft_matrix(t_sprites *s, t_game *g, int *order, int i)
// {
// 	//s->spriteX = g->sprites.sprite[order[i]]->x - g->player.pos.x;
// 	// s->spriteY = g->sprites.sprite[order[i]]->y - g->player.pos.y;
// 	// s->lyambda = 1.0 / (g->ray.plane.x * g->player.dir.y - g->player.dir.x * g->ray.plane.y);
//     // s->transformX = s->lyambda * (g->player.dir.y * s->spriteX - g->player.dir.x * s->spriteY);
//     // s->transformY = s->lyambda * (-g->ray.plane.y * s->spriteX + g->ray.plane.x * s->spriteY);
//     // s->screenX = (int)((g->map.R[0] / 2) * (1 + s->transformX / s->transformY));
// //	s->s_h = abs((int)(s->s_h / s->transformY));
// }

// void	ft_tex_sprite(t_game *g, t_sprites *s)
// {
// 	s->start_y = -s->s_h / 2 + g->map.R[1] / 2;
// 	if (s->start_y < 0)
// 		s->start_y = 0;
// 	s->end_y = s->s_h / 2 + g->map.R[1] / 2;
// 	if (s->end_y >= g->map.R[1])
// 		s->end_y = g->map.R[1] - 1;
// 	s->s_w = abs((int)(g->map.R[1] / s->transformY));
// 	s->start_x = -s->s_w / 2 + s->screenX;
// 	if (s->start_x < 0)
// 		s->start_x = 0;
// 	s->end_x = s->s_w / 2 + s->screenX;
// 	// if (s->end_x >= g->map.R[0])
// 	// 	s->end_x = g->map.R[0] - 1;
// }

// void	ft_final_sprite(t_game *g, t_sprites *s)
// {
// 	int x;
// 	int texy;
// 	int color;

// 	while (s->spriteY < s->end_y)
// 	{
// 		x = s->spriteY * 256 - g->map.R[1] * 128 + s->s_h * 128;
// 		texy = ((x * g->sprites.tex.X) / s->s_h) / 256;
// 		s->color = ((int*)s->tex.img.addr)
// 		[(int)(s->tex.X * s->texY + s->texX)];
// 		if (color != -0x1000000)
// 			my_mlx_pixel_put(&g->img, g->sprites.spriteX, g->sprites.spriteY, color);
// 		g->sprites.spriteY++;
// 	}
// }

// void	ft_draw_sprite(t_game *g, t_sprites *s, double *buf)
// {
// 	s->ok = s->start_x;
// 	while (s->ok < s->end_x)
// 	{
// 		s->hi = s->start_y;
// 		s->texX = (int)256 * (s->ok - (-s->s_w / 2 + s->screenX));
// 		s->texX = s->texX * s->tex.X / s->s_w / 256;
// 		if (s->transformY > 0 && s->ok > 0 && s->ok < s->s_w
// 				&& s->transformY < buf[s->ok])
// 			ft_final_sprite(g, s);
// 		s->ok++;
// 	}
// }

// void	ft_sprite(t_game *g, double *buf)
// {
// 	t_sprites	s;
// 	int			i;
// 	double		dist[g->sprites.nums];
// 	int			order[g->sprites.nums];

// 	i = 0;
// 	// s = g->sprites;
// 	while (i < g->sprites.nums)
// 	{
// 		order[i] = i;
// 		dist[i] = pow((g->player.pos.x - g->sprites.sprite[i]->x), 2);
// 		dist[i] += pow((g->player.pos.y - g->sprites.sprite[i]->y), 2);
// 		i++;
// 	}
// 	i = 0;
// 	quick_sort(dist, order, g->sprites.nums);
// 	while (i < g->sprites.nums)
// 	{
// 		ft_matrix(&s, g, order, i);
// 	//	ft_tex_sprite(g, &s);
// 	//	ft_draw_sprite(g, &s, buf);
// 		i++;
// 	}
// }