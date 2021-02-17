/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 21:45:54 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 04:16:19 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

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
	if (map->NO != NULL)
	{
		free(map->NO);
		map->NO = NULL;
	}
	if (map->SO != NULL)
	{
		free(map->SO);
		map->SO = NULL;
	}
	if (map->WE != NULL)
	{
		free(map->WE);
		map->WE = NULL;
	}
	if (map->EA != NULL)
	{
		free(map->EA);
		map->EA = NULL;
	}
	if (map->S != NULL)
	{
		free(map->S);
		map->S = NULL;
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
	map->R[0] = 0;
	map->R[1] = 0;
	map->F = -1;
	map->C = -1;
}

int				free_map(t_map *map)
{
	free_rfc(map);
	free_tex(map);
	free_strs(&(map->map));
	return (GOOD);
}
