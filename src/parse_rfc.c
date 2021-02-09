/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rfc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 11:59:23 by yzena             #+#    #+#             */
/*   Updated: 2021/01/30 12:53:17 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_rfc.h"

int check_resolution(t_strs s, t_map *map)
{
	if (!(ft_is_digit(s.strs[1], 0)) || !(ft_is_digit(s.strs[2], 0)))
		return (ERROR);
	if (ft_number_cmp(s.strs[1], "5120") >= 0)
	{
		map->R[0] = 2880;
		return (BAD);
	}
	else
		map->R[0] = ft_atoi(s.strs[1]);
	
	if (ft_number_cmp(s.strs[2], "2880") >= 0)
	{
		map->R[1] = 1575;
		return (BAD);
	}
	else
		map->R[1] = ft_atoi(s.strs[2]);

	return (GOOD);
}

int	resolution(t_strs s, t_map *map)
{
	int check;

	check = check_resolution(s, map);
	if (!check)
	{
		if (map->R[0] == 0)
			map->R[0] = ft_atoi(s.strs[1]);
		if (map->R[1] == 0)
			map->R[1] = ft_atoi(s.strs[2]);
	}
	return (GOOD);
}

int	ft_floor(t_strs s, t_map *map)
{
	size_t		i;
	size_t		cc;
	t_strs		cf;

	i = 0;
	cc = 0;
	while (s.strs[1][i] != '\0')
	{
		if (s.strs[1][i] && ft_chr_find(",", s.strs[1][i++]))
			cc++;
	}
	if (cc != 2)
		return (ERROR);
	if (!(cf.strs = ft_split(s.strs[1], ',')))
		return (ERROR);
	map->F = (ft_atoi(cf.strs[0]) * 65536 + ft_atoi(cf.strs[1]) * 256 + ft_atoi(cf.strs[2]));
	return (GOOD);
}

int	ceiling(t_strs s, t_map *map)
{
	size_t		i;
	size_t		cc;
	t_strs		color;

	i = 0;
	cc = 0;
	while (s.strs[1][i] != '\0')
	{
		if (ft_chr_find(",", s.strs[1][i++]))
			cc++;
	}
	if (cc != 2)
		return (ERROR);
	if (!(color.strs = ft_split(s.strs[1], ',')))
		return (ERROR);
	map->C = (ft_atoi(color.strs[0]) * 65536 + ft_atoi(color.strs[1]) * 256 + ft_atoi(color.strs[2]));
	return (TRUE);
}
