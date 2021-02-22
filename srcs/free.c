/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:45:54 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int				free_sprites(t_double_vec ***sprites)
{
	size_t	i;

	if (sprites == NULL)
		return (0);
	if (*sprites == NULL)
		return (0);
	i = 0;
	while ((*sprites)[i] != NULL)
	{
		free((*sprites)[i]);
		(*sprites)[i] = NULL;
		i++;
	}
	free(*sprites);
	*sprites = NULL;
	return (0);
}

static void		free_tex(t_map *map)
{
	if (map->no != NULL)
	{
		free(map->no);
		map->no = NULL;
	}
	if (map->so != NULL)
	{
		free(map->so);
		map->so = NULL;
	}
	if (map->we != NULL)
	{
		free(map->we);
		map->we = NULL;
	}
	if (map->ea != NULL)
	{
		free(map->ea);
		map->ea = NULL;
	}
	if (map->s != NULL)
	{
		free(map->s);
		map->s = NULL;
	}
}

void			free_strs(char ***strs)
{
	int	i;

	if (strs == NULL)
		return ;
	if (*strs == NULL)
		return ;
	i = 0;
	while ((*strs)[i] != NULL)
	{
		free((*strs)[i]);
		(*strs)[i] = NULL;
		i++;
	}
	free(*strs);
	*strs = NULL;
}

static void		free_rfc(t_map *map)
{
	map->r[0] = 0;
	map->r[1] = 0;
	map->f = -1;
	map->c = -1;
}

int				free_map(t_map *map)
{
	free_rfc(map);
	free_tex(map);
	free_strs(&(map->map));
	return (GOOD);
}
