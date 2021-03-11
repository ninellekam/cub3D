/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_tex_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:48 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 16:26:56 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	init_img_no_tex(void *mlx, t_tex *texture)
{
	t_t				*no;
	t_tex2			*no_img;

	no = &texture->NO;
	no_img = &no->img;
	no_img->img = mlx_xpm_file_to_image(mlx,
			no->relative_path, &no->X, &no->Y);
	if (!(no_img->img))
	{
		write(2, "ER_T: CAN'T OPEN 'NO' TEXTURE\n", 34);
		exit(-1);
	}
	no_img->addr = (int*)mlx_get_data_addr(no_img->img,
			&no_img->bits_per_pixel, &no_img->line_length, &no_img->endian);
	return (GOOD);
}

int	init_img_so_tex(void *mlx, t_tex *texture)
{
	t_t				*so;
	t_tex2			*so_img;

	so = &texture->SO;
	so_img = &so->img;
	so_img->img = mlx_xpm_file_to_image(mlx,
			so->relative_path, &so->X, &so->Y);
	if (!(so_img->img))
	{
		write(1, "ER_T: CAN'T OPEN 'SO' TEXTURE\n", 35);
		exit(-1);
	}
	so_img->addr = (int*)mlx_get_data_addr(so_img->img,
			&so_img->bits_per_pixel, &so_img->line_length, &so_img->endian);
	return (GOOD);
}

int	init_img_we_tex(void *mlx, t_tex *texture)
{
	t_t			*we;
	t_tex2		*we_img;

	we = &texture->WE;
	we_img = &we->img;
	we_img->img = mlx_xpm_file_to_image(mlx,
			we->relative_path, &we->X, &we->Y);
	if (!(we_img->img))
	{
		write(1, "ER_T: CAN'T OPEN 'WE' TEXTURE\n", 34);
		exit(-1);
	}
	we_img->addr = (int*)mlx_get_data_addr(we_img->img,
			&we_img->bits_per_pixel, &we_img->line_length, &we_img->endian);
	return (GOOD);
}

int	init_img_ea_tex(void *mlx, t_tex *texture)
{
	t_t			*ea;
	t_tex2		*ea_img;

	ea = &texture->EA;
	ea_img = &ea->img;
	ea_img->img = mlx_xpm_file_to_image(mlx,
			ea->relative_path, &ea->X, &ea->Y);
	if (!(ea_img->img))
	{
		write(1, "ER_T: CAN'T OPEN 'EA' TEXTURE\n", 34);
		exit(-1);
	}
	ea_img->addr = (int*)mlx_get_data_addr(ea_img->img,
			&ea_img->bits_per_pixel, &ea_img->line_length, &ea_img->endian);
	return (GOOD);
}
