/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:46:10 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/07 16:12:24 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_button(t_button *but)
{
	but->w = 0;
	but->s = 0;
	but->a = 0;
	but->d = 0;
}

int		raycasting_render(t_game *game)
{
	t_mlx		*mlx;
	t_ray		*r;
	size_t		i;
	size_t		nums;
	double		mas[game->map.R[0]];

	mlx = &game->mlx;
	r = &game->ray;
	move_player(game);
	i = 0;
	while (i < game->map.R[0])
	{
		init_ray_1(game, i);
		ray(game);
		draw_tex(game, i);
		mas[i] = r->perp_wall_dist;
		i++;
	}
	sprites(game, mas);
	mlx_put_image_to_window(mlx->mlx, mlx->win, game->img.img, 0, 0);
	return (0);
}
