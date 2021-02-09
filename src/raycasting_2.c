/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:50:39 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/04 14:48:15 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "game.h"

// void	draw_sky(t_game *game)
// {
// 	size_t	x;
// 	size_t	y;
// 	size_t	color;

// 	y = 0;
// 	color = game->map.C;
// 	while (y < game->map.R[1] / 2)
// 	{
// 		x = 0;
// 		while (x < game->map.R[0])
// 		{
// 			my_mlx_pixel_put(&game->img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	draw_ground(t_game *game)
// {
// 	size_t	x;
// 	size_t	y;
// 	size_t	color;

// 	y = game->map.R[1] / 2;
// 	color = game->map.F;
// 	while (y < game->map.R[1])
// 	{
// 		x = 0;
// 		while (x < game->map.R[0])
// 		{
// 			my_mlx_pixel_put(&game->img, x, y, color);
// 			x++;
// 		}
// 		y++;
// 	}
// }
