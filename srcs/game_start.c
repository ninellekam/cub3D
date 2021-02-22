/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:25:29 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/21 17:59:13 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "../mlx/mlx.h"

int		ft_error2(t_cub *p)
{
	mlx_destroy_window(p->mlx.mlx, p->mlx.win);
	exit(-1);
	return (1);
}

int		init_img(t_img *img, t_mlx *mlx, t_map *map)
{
	img->img = mlx_new_image(mlx->mlx, map->r[0], map->r[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	return (0);
}

void	init_win_img(t_mlx *mlx, t_img *img, t_map *map)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, map->r[0], map->r[1], "CUB3D");
	img->img = mlx_new_image(mlx->mlx, map->r[0], map->r[1]);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	cub_start(t_map *map, char *argv, char *file_name)
{
	t_mlx	mlx;
	t_img	img;
	t_cub	g;

	init_win_img(&mlx, &img, map);
	init_cub_s_player_button(&g, &img, &mlx, map);
	raycast_one_frame(&g);
	if ((argv) && ft_strlen(argv) != 6)
	{
		write(1, "ERROR: in --save", 17);
		exit(-1);
	}
	if (!(ft_strcmp(argv, "--save")))
	{
		ft_bmp(file_name, &g);
		exit(-1);
	}
	mlx_loop_hook(mlx.mlx, raycast, &g);
	mlx_hook(mlx.win, 2, (1L << 0), button_pressed, &g);
	mlx_hook(mlx.win, 17, 0, ft_error2, &g);
	mlx_hook(mlx.win, 3, (1L << 1), button_unpressed, &g);
	mlx_loop(mlx.mlx);
}
