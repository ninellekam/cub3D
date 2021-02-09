/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_tex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:46:40 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/02 17:59:56 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "game.h"

int		valid_xpm(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == '.')
			if (ft_strcmp(s + i, ".xpm") == 0)
				return (GOOD);
		i--;
	}
	write(2, "ER_T: invalid textures\n", 24);
	return (ERROR);
}

void		init_relative_path(t_tex *texture, t_map *map)
{
	texture->NO.relative_path = map->NO;
	valid_xpm(texture->NO.relative_path);
	texture->SO.relative_path = map->SO;
	valid_xpm(texture->SO.relative_path);
	texture->WE.relative_path = map->WE;
	valid_xpm(texture->WE.relative_path);
	texture->EA.relative_path = map->EA;
	valid_xpm(texture->EA.relative_path);
}

void	init_img_tex(void *mlx, t_tex *tex)
{
	init_img_no_tex(mlx, tex);
	init_img_so_tex(mlx, tex);
	init_img_we_tex(mlx, tex);
	init_img_ea_tex(mlx, tex);
}

void		init_tex_sides(t_game *game)
{
	t_tex		*texture;
	t_map		*map;

	texture = &game->tex;
	map = &game->map;
	init_relative_path(&game->tex, &game->map);
	init_img_tex(game->mlx.mlx, &game->tex);
}
