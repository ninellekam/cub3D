/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_tex_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:24 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	write(2, "ERROR: invalid textures\n", 25);
	return (ERROR);
}

void	init_relative_path(t_tex *texture, t_map *map)
{
	texture->no.relative_path = map->no;
	if (valid_xpm(texture->no.relative_path) == ERROR)
		exit(-1);
	texture->so.relative_path = map->so;
	if (valid_xpm(texture->so.relative_path) == ERROR)
		exit(-1);
	texture->we.relative_path = map->we;
	if (valid_xpm(texture->we.relative_path) == ERROR)
		exit(-1);
	texture->ea.relative_path = map->ea;
	if (valid_xpm(texture->ea.relative_path) == ERROR)
		exit(-1);
}

void	init_img_tex(void *mlx, t_tex *tex)
{
	init_img_no_tex(mlx, tex);
	init_img_so_tex(mlx, tex);
	init_img_we_tex(mlx, tex);
	init_img_ea_tex(mlx, tex);
}

void	init_tex_sides(t_cub *cub)
{
	t_tex		*texture;
	t_map		*map;

	texture = &cub->tex;
	map = &cub->map;
	init_relative_path(&cub->tex, &cub->map);
	init_img_tex(cub->mlx.mlx, &cub->tex);
}
