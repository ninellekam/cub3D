/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:25:59 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/21 13:26:02 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_cub(t_cub *g, t_mlx *mlx, t_img *img, t_map *map)
{
	g->mlx = *mlx;
	g->img = *img;
	g->map = *map;
}

void	init_cub_s_player_button(t_cub *g, t_img *img, t_mlx *mlx, t_map *map)
{
	init_cub(g, mlx, img, map);
	init_sprites(g);
	init_tex_sides(g);
	init_player(&g->player, &g->ray.plane, g->map.map);
	init_button(&g->button);
}

int		finish_cub(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	free_map(&cub->map);
	free_sprites(&cub->sprites.sprite);
	exit(0);
	return (0);
}
