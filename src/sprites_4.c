/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:53:19 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/09 13:29:14 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_color(t_game *game, double hi)
{
	t_sprites	*s;
	double		d;

	s = &game->sprites;
	d = s->hi * 256 - game->map.R[1] * 128 +
		s->s_h * 128;
	s->texY = ((d * s->tex.Y) /
			s->s_h) / 256;
	s->color = ((int*)s->tex.img.addr)
		[(int)(s->tex.X * s->texY + s->texX)];
}


static int	need_drawing(t_game *game, double *mas)
{
	t_sprites	*s;

	s = &game->sprites;
	return (s->transformY > 0 && s->ok > 0 &&
			s->ok < game->map.R[0] &&
			s->transformY < mas[s->ok]);
}

void    sprites_3(t_game *game, double *mas)
{
    size_t      ok;
    size_t      hi;
    t_sprites   *s;

    s = &game->sprites;
    s->ok = s->start_x;
    while (s->ok < s->end_x)
    {
		s->texX = (int)(256 * (s->ok -
					(-s->s_w / 2 + s->screenX)) *
				s->tex.X / s->s_w) / 256;
		if (need_drawing(game, mas))
		{
			s->hi = s->start_y;
			while (s->hi < s->end_y)
			{
				init_color(game, s->hi);
				if ((s->color & 0x00FFFFFF) != 9961608)
					my_mlx_pixel_put(&game->img, s->ok,
							s->hi, s->color);
				s->hi++;
			}
		}
		s->ok++;
	}
}