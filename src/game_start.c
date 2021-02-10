/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:37:31 by yzena             #+#    #+#             */
/*   Updated: 2021/02/10 12:58:27 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void    my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     init_win(t_mlx *mlx, t_map *map)
{
    void *win;

    mlx->mlx = mlx_init();
    mlx->win = mlx_new_window(mlx->mlx, map->R[0], map->R[1], "CUB3D");
    return (0);
}

int	    init_img(t_img *img, t_mlx *mlx, t_map *map)
{
	img->img = mlx_new_image(mlx->mlx, map->R[0], map->R[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}

void    init_game(t_game *g, t_mlx *mlx, t_img *img, t_map *map)
{
    g->mlx = *mlx;
    g->img = *img;
    g->map = *map;
}

int     game_start(t_map *map)
{
    t_mlx   mlx;
    t_img   img;
    t_game  g;

    init_win(&mlx, map);
    init_img(&img, &mlx, map);
    init_game(&g, &mlx, &img, map);
    init_sprites(&g);
    init_tex_sides(&g);
    init_player(&(g.player), &(g.ray.plane), g.map.map);
    init_button(&(g.button));
    mlx_hook(g.mlx.win, 2, 1L<<0, button_pressed, &g);
    mlx_hook(g.mlx.win, 3, 1L<<1, button_unpressed, &g);
    mlx_loop_hook(g.mlx.mlx, raycasting_render, &g);
    mlx_loop(g.mlx.mlx);
    return (0);
}