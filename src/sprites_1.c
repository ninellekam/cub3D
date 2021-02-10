/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 17:02:26 by yzena             #+#    #+#             */
/*   Updated: 2021/02/10 12:47:17 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	sprites_num(t_game *game)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
    char    **map;

    map = game->map.map;
    size_t nums = 0;
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

void    sprites_array_2(t_game *game, size_t nums, int x, int y)
{
    game->sprites.sprite[nums] = (t_double_vec*)malloc(sizeof(t_double_vec));
	if (!(game->sprites.sprite[nums]))
		exit(-1);
	game->sprites.sprite[nums]->x = (double)x + 0.5;
	game->sprites.sprite[nums]->y = (double)y + 0.5;
	if (nums == 1)
		printf("  D %f ", game->sprites.sprite[1]->x);
}

int	sprites_array_1(t_game *game)
{
	size_t	player_count;
	size_t	x;
	size_t	y;
    char    **map;

    map = game->map.map;
    size_t nums = 0;
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
			{
				sprites_array_2(game, nums, x, y);
				nums++;
			}
			x++;
		}
		y++;
	}
	return (BAD);
}

void	init_sprites(t_game *game)
{
	size_t num;

	num = sprites_num(game);
	game->sprites.sprite = (t_double_vec**)malloc(sizeof(t_double_vec*) * (num + 1));
	game->sprites.sprite[num] = NULL;
	sprites_array_1(game);
	printf(" U %f", game->sprites.sprite[1]->x);
	draw_sprites(game);
}
