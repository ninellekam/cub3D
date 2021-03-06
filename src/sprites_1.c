/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:31:11 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:31:12 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	draw_sprites(t_game *game)
{
	t_map				*map;

	map = &game->map;
	game->sprites.tex.relative_path = map->S;
	game->sprites.tex.img.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->sprites.tex.relative_path,
				&game->sprites.tex.X, &game->sprites.tex.Y);
	if (!(game->sprites.tex.img.img))
		exit(-1);
	game->sprites.tex.img.addr = (int*)
		mlx_get_data_addr(game->sprites.tex.img.img,
	&game->sprites.tex.img.bits_per_pixel,
		&game->sprites.tex.img.line_length,
			&game->sprites.tex.img.endian);
}

int		sprites_num(t_game *game)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
	char	**map;
	size_t	nums;

	nums = 0;
	map = game->map.map;
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
	game->sprites.nums = nums;
	return (nums);
}

void	sprites_array_2(t_game *game, size_t nums, int x, int y)
{
	game->sprites.sprite[nums] = (t_double_vec*)malloc(sizeof(t_double_vec));
	if (!(game->sprites.sprite[nums]))
		exit(-1);
	game->sprites.sprite[nums]->x = (double)x + 0.5;
	game->sprites.sprite[nums]->y = (double)y + 0.5;
}

int		sprites_array_1(t_game *game)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
	char	**map;
	size_t	nums;

	nums = -1;
	map = game->map.map;
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
				sprites_array_2(game, ++nums, x, y);
			x++;
		}
		y++;
	}
	return (BAD);
}

void	init_sprites(t_game *game)
{
	size_t	num;

	num = sprites_num(game);
	game->sprites.sprite = (t_double_vec**)malloc(sizeof(t_double_vec)
		* (num + 1));
	game->sprites.sprite[num] = NULL;
	draw_sprites(game);
	sprites_array_1(game);
}
