/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rfc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:44 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 15:54:54 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	ft_resolution(t_strs s, t_map *map)
{
	if (!(ft_is_digit(s.strs[1], 0)) || !(ft_is_digit(s.strs[2], 0)))
		return (ERROR);
	map->R[0] = ft_atoi(s.strs[1]);
	map->R[1] = ft_atoi(s.strs[2]);
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
	map->F = (ft_atoi(cf.strs[0]) * 65536 +
		ft_atoi(cf.strs[1]) * 256 +
			ft_atoi(cf.strs[2]));
	free_strs(&cf.strs);
	return (GOOD);
}

int	ft_ceiling(t_strs s, t_map *map)
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
	map->C = (ft_atoi(color.strs[0]) * 65536
		+ ft_atoi(color.strs[1]) * 256
			+ ft_atoi(color.strs[2]));
	free_strs(&color.strs);
	return (TRUE);
}
