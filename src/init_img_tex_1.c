/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_tex_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:24 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 16:27:49 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		valid_xpm(char *str)
{
	int i;
	int len;

	i = 0;
	if (str == NULL)
		return (ERROR);
	len = ft_strlen(str);
	if (len < 4)
		return (ERROR);
	while (i != len - 3)
	{
		if (!(ft_strcmp(str + i, ".xpm")))
			return (GOOD);
		i++;
	}
	write(2, "ER_T: invalid textures\n", 24);
	return (ERROR);
}

void	init_relative_path(t_tex *texture, t_map *map)
{
	texture->NO.relative_path = map->NO;
	if (valid_xpm(texture->NO.relative_path) == ERROR)
		exit(-1);
	texture->SO.relative_path = map->SO;
	if (valid_xpm(texture->SO.relative_path) == ERROR)
		exit(-1);
	texture->WE.relative_path = map->WE;
	if (valid_xpm(texture->WE.relative_path) == ERROR)
		exit(-1);
	texture->EA.relative_path = map->EA;
	if (valid_xpm(texture->EA.relative_path) == ERROR)
		exit(-1);
}

void	init_img_tex(void *mlx, t_tex *tex)
{
	init_img_no_tex(mlx, tex);
	init_img_so_tex(mlx, tex);
	init_img_we_tex(mlx, tex);
	init_img_ea_tex(mlx, tex);
}

void	init_tex_sides(t_game *game)
{
	t_tex		*texture;
	t_map		*map;

	texture = &game->tex;
	map = &game->map;
	init_relative_path(&game->tex, &game->map);
	init_img_tex(game->mlx.mlx, &game->tex);
}
