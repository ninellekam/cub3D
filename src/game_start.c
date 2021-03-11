/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:37:31 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 17:14:25 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		ft_error2(t_game *p)
{
	mlx_destroy_window(p->mlx.mlx, p->mlx.win);
	exit(-1);
	return (1);
}

int		init_img(t_img *img, t_mlx *mlx, t_map *map)
{
	img->img = mlx_new_image(mlx->mlx, map->R[0], map->R[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}

void	init_win_img(t_mlx *mlx, t_img *img, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->R[0], map->R[1], "CUB3D");
	img->img = mlx_new_image(mlx->mlx, map->R[0], map->R[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	game_start(t_map *map, char *argv, char *file_name)
{
	t_mlx	mlx;
	t_img	img;
	t_game	g;

	if (ft_number_cmp(ft_itoa(map->R[0]), "5120") >= 0
		|| ft_number_cmp(ft_itoa(map->R[1]), "2880") >= 0)
		mlx_get_screen_size(mlx.mlx, &map->R[0], &map->R[1]);
	init_win_img(&mlx, &img, map);
	init_game_s_player_button(&g, &img, &mlx, map);
	raycasting_render_one_frame(&g);
	if (!(ft_strcmp(argv, "--save")))
	{
		ft_bmp(file_name, &g);
		return ;
	}
	mlx_loop_hook(mlx.mlx, raycasting_render, &g);
	mlx_hook(mlx.win, 2, (1L << 0), button_pressed, &g);
	mlx_hook(mlx.win, 17, 0, ft_error2, &g);
	mlx_hook(mlx.win, 3, (1L << 1), button_unpressed, &g);
	mlx_loop(mlx.mlx);
}
