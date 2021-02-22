/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:31:11 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_sprites(t_cub *cub)
{
	t_map				*map;

	map = &cub->map;
	cub->sprites.tex.relative_path = map->s;
	cub->sprites.tex.img.img = mlx_xpm_file_to_image(cub->mlx.mlx,
			cub->sprites.tex.relative_path,
				&cub->sprites.tex.width, &cub->sprites.tex.height);
	if (!(cub->sprites.tex.img.img))
	{
		write(1, "ERROR: Sprite texture\n", 23);
		exit(-1);
	}
	cub->sprites.tex.img.addr = (int*)
		mlx_get_data_addr(cub->sprites.tex.img.img,
	&cub->sprites.tex.img.bits_per_pixel,
		&cub->sprites.tex.img.line_length,
			&cub->sprites.tex.img.endian);
}

int		sprites_num(t_cub *cub)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
	char	**map;
	size_t	nums;

	nums = 0;
	map = cub->map.map;
	if (map == NULL)
		return (BAD);
	player_count = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_strchr("2", map[y][x]))
				nums++;
			x++;
		}
		y++;
	}
	cub->sprites.nums = nums;
	return (nums);
}

void	sprites_array_2(t_cub *cub, size_t nums, int x, int y)
{
	cub->sprites.sprite[nums] = (t_double_vec*)malloc(sizeof(t_double_vec));
	if (!(cub->sprites.sprite[nums]))
		exit(-1);
	cub->sprites.sprite[nums]->x = (double)x + 0.5;
	cub->sprites.sprite[nums]->y = (double)y + 0.5;
}

int		sprites_array_1(t_cub *cub)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
	char	**map;
	size_t	nums;

	nums = -1;
	map = cub->map.map;
	if (map == NULL)
		return (BAD);
	player_count = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_strchr("2", map[y][x]))
				sprites_array_2(cub, ++nums, x, y);
			x++;
		}
		y++;
	}
	return (BAD);
}

void	init_sprites(t_cub *cub)
{
	size_t	num;

	num = sprites_num(cub);
	cub->sprites.sprite = (t_double_vec**)malloc(sizeof(t_double_vec)
		* (num + 1));
	cub->sprites.sprite[num] = NULL;
	draw_sprites(cub);
	if (valid_xpm(cub->sprites.tex.relative_path) == ERROR)
	{
		write(1, "ERROR: Sprite texture\n", 23);
		exit(-1);
	}
	sprites_array_1(cub);
}
