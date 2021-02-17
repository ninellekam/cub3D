/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:24 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 15:59:12 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	init_check(t_map *map)
{
	if (map->R[0] == -1)
		return (ERROR);
	if (map->R[1] == -1)
		return (ERROR);
	if (map->NO == 0)
		return (ERROR);
	if (map->SO == 0)
		return (ERROR);
	if (map->WE == 0)
		return (ERROR);
	if (map->EA == 0)
		return (ERROR);
	if (map->S == 0)
		return (ERROR);
	if (map->F == -1)
		return (ERROR);
	if (map->C == -1)
		return (ERROR);
	return (GOOD);
}

int	parse_rfc(t_strs s, t_map *map)
{
	int check;

	if (s.len == 3 && is_resolution(s.strs[0]))
	{
		check = ft_resolution(s, map);
		return (check);
	}
	if (s.len == 2 && is_floor(s.strs[0]))
	{
		check = ft_floor(s, map);
		return (check);
	}
	if (s.len == 2 && is_ceiling(s.strs[0]))
	{
		check = ft_ceiling(s, map);
		return (check);
	}
	return (BAD);
}

int	parse_no_so_we(t_strs s, t_map *map)
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

int	parse_ea_s(t_strs s, t_map *map)
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
	int	check;

	if ((check = parse_rfc(s, map)) == ERROR)
		return (ERROR);
	if ((check = parse_no_so_we(s, map)) == ERROR)
		return (ERROR);
	check = parse_ea_s(s, map);
	return (check);
}
