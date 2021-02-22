/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:31:06 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_button(t_button *but)
{
	but->w = 0;
	but->s = 0;
	but->a = 0;
	but->d = 0;
	but->left = 0;
	but->right = 0;
}

int		raycast(t_cub *cub)
{
	t_mlx		*mlx;
	int			i;
	double		mas[cub->map.r[0]];

	if (!(cub->button.w || cub->button.s
		|| cub->button.d || cub->button.a || cub->button.left
		|| cub->button.right))
		return (0);
	mlx = &cub->mlx;
	move_player(cub);
	i = -1;
	init_img(&cub->img, &cub->mlx, &cub->map);
	while (++i < cub->map.r[0])
	{
		init_ray_0(cub, i);
		ray(cub);
		draw_tex(cub, i);
		mas[i] = cub->ray.perp_wall_dist;
	}
	ft_sprite(cub, mas);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	return (0);
}

int		raycast_one_frame(t_cub *cub)
{
	t_mlx		*mlx;
	t_ray		*r;
	int			i;
	double		mas[cub->map.r[0]];

	mlx = &cub->mlx;
	r = &cub->ray;
	move_player(cub);
	i = 0;
	init_img(&cub->img, &cub->mlx, &cub->map);
	while (i < cub->map.r[0])
	{
		init_ray_0(cub, i);
		ray(cub);
		draw_tex(cub, i);
		mas[i] = r->perp_wall_dist;
		i++;
	}
	ft_sprite(cub, mas);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->img.img, 0, 0);
	mlx_destroy_image(cub->mlx.mlx, cub->img.img);
	return (0);
}
