/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:22:20 by yzena             #+#    #+#             */
/*   Updated: 2021/02/07 16:48:19 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void		draw_sprites(t_game *game)
{
	t_map				*map;
	map = &game->map;
//	sprites_array_1(game);
//	check_dot_xpm(map->s);
	game->sprites.tex.relative_path = map->S;
	game->sprites.tex.img.img = mlx_xpm_file_to_image(game->mlx.mlx,
			game->sprites.tex.relative_path, &game->sprites.tex.X, &game->sprites.tex.Y);
	if (!(game->sprites.tex.img.img))
		exit(-1);
    game->sprites.tex.img.addr = mlx_get_data_addr(game->sprites.tex.img.img,
        &game->sprites.tex.img.bits_per_pixel, &game->sprites.tex.img.line_length, &game->sprites.tex.img.endian);
}
