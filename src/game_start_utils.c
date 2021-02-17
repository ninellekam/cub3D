/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:04:04 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 04:15:55 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_game(t_game *g, t_mlx *mlx, t_img *img, t_map *map)
{
	g->mlx = *mlx;
	g->img = *img;
	g->map = *map;
}

void	init_game_s_player_button(t_game *g, t_img *img, t_mlx *mlx, t_map *map)
{
	init_game(g, mlx, img, map);
	init_sprites(g);
	init_tex_sides(g);
	init_player(&g->player, &g->ray.plane, g->map.map);
	init_button(&g->button);
}

int		finish_game(t_game *game)
{
	mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	free_map(&game->map);
	free_sprites(&game->sprites.sprite);
	exit(0);
	return (0);
}
