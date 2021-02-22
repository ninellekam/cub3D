/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:24 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 17:40:45 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	init_check(t_map *map)
{
	if (map->r[0] == -1)
		return (ERROR);
	if (map->r[1] == -1)
		return (ERROR);
	if (map->no == 0)
		return (ERROR);
	if (map->so == 0)
		return (ERROR);
	if (map->we == 0)
		return (ERROR);
	if (map->ea == 0)
		return (ERROR);
	if (map->s == 0)
		return (ERROR);
	if (map->f == -1)
		return (ERROR);
	if (map->c == -1)
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
		if (map->no != NULL)
			return (ERROR);
		if (!(map->no = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_so(s.strs[0]))
	{
		if (map->so != NULL)
			return (ERROR);
		if (!(map->so = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_we(s.strs[0]))
	{
		if (map->we != NULL)
			return (ERROR);
		if (!(map->we = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	return (BAD);
}

int	parse_ea_s(t_strs s, t_map *map)
{
	if (s.len == 2 && is_ea(s.strs[0]))
	{
		if (map->ea != NULL)
			return (ERROR);
		if (!(map->ea = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	if (s.len == 2 && is_s(s.strs[0]))
	{
		if (map->s != NULL)
			return (ERROR);
		if (!(map->s = ft_strdup(s.strs[1])))
			return (ERROR);
		return (GOOD);
	}
	return (BAD);
}

int	parse_initialize(t_strs s, t_map *map)
{
	static int	check1;
	static int	check2;

	if (s.strs[0])
		if ((ft_chr_find("RNSWEAO 012NFC", s.strs[0][0]) == NULL))
		{
			write(1, "ERROR: ARGS IN MAP", 20);
			exit(-1);
		}
	if ((check1 = parse_rfc(s, map)) == ERROR)
		return (ERROR);
	if ((check2 = parse_no_so_we(s, map)) == ERROR)
		return (ERROR);
	check1 = parse_ea_s(s, map);
	return (check1);
}
