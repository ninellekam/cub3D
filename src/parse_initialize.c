/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 21:25:59 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/06 16:54:23 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_initialize.h"

// ------------------------- technic part - R C F --------------------------------------------
int	 parse_tech(t_strs s, t_map *map)
{
	int check;
	if (s.len == 3 && is_resolution(s.strs[0]))
	{
		check = resolution(s, map);
		return (check);
	}
	if (s.len == 2 && is_floor(s.strs[0]))
	{
		check = ft_floor(s, map);
		return (check);
	}
	if (s.len == 2 && is_ceiling(s.strs[0]))
	{
		check = ceiling(s, map);
		return (check);
	}
	return (BAD);
}

int	 parse_tex_1(t_strs s, t_map *map)
{
	if (s.len == 2 && is_no(s.strs[0]))
	{
		if (map->NO != NULL)
			return (ERROR);
		if (!(map->NO = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_so(s.strs[0]))
	{
		if (map->SO != NULL)
			return (ERROR);
		if (!(map->SO = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_we(s.strs[0]))
	{
		if (map->WE != NULL)
			return (ERROR);
		if (!(map->WE = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	return (BAD);
}

// -------- no so we ea s -------------------------------------

int	 parse_tex_2(t_strs s, t_map *map)
{
	if (s.len == 2 && is_ea(s.strs[0]))
	{
		if (map->EA != NULL)
			return (ERROR);
		if (!(map->EA = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_s(s.strs[0]))
	{
		if (map->S != NULL)
			return (ERROR);
		if (!(map->S = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	return (BAD);
}

int	parse_initialize(t_strs s, t_map *map)
{
	int		check;
	check = parse_tech(s, map);
	if (check == BAD)
		check = parse_tex_1(s, map);
	if (check == BAD)
		check = parse_tex_2(s, map);
	return (check);
}