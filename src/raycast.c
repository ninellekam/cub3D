/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:31:06 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 20:13:34 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	init_button(t_button *but)
{
	but->w = 0;
	but->s = 0;
	but->a = 0;
	but->d = 0;
	but->left = 0;
	but->right = 0;
}

int		raycasting_render(t_game *game)
{
	t_mlx		*mlx;
	t_ray		*r;
	size_t		i;
	size_t		nums;
	double		mas[game->map.R[0]];

	if (!(game->button.w || game->button.s
		|| game->button.d || game->button.a || game->button.left
		|| game->button.right))
		return (0);
	mlx = &game->mlx;
	move_player(game);
	i = -1;
	init_img(&game->img, &game->mlx, &game->map);
	while (++i < game->map.R[0])
	{
		init_ray_0(game, i);
		ray(game);
		draw_tex(game, i);
		mas[i] = game->ray.perp_wall_dist;
	}
	ft_sprite(game, mas);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx.mlx, game->img.img);
	return (0);
}

int		raycasting_render_one_frame(t_game *game)
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
	init_img(&game->img, &game->mlx, &game->map);
	while (i < game->map.R[0])
	{
		init_ray_0(game, i);
		ray(game);
		draw_tex(game, i);
		mas[i] = r->perp_wall_dist;
		i++;
	}
	ft_sprite(game, mas);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx.mlx, game->img.img);
	return (0);
}
