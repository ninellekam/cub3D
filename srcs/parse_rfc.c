/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rfc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshantel <kshantel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:44 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 14:05:37 by kshantel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		ft_resolution(t_strs s, t_map *map)
{
	int	w;
	int	h;

	if (map->r[0] != -1 || map->r[1] != -1)
	{
		write(1, "ERROR RESOLUTION", 17);
		exit(-1);
	}
	if (!(ft_is_digit(s.strs[1], 0)) || !(ft_is_digit(s.strs[2], 0)))
		return (ERROR);
	if (!(ft_strcmp(s.strs[1], "0")) || !(ft_strcmp(s.strs[2], "0")))
	{
		write(1, "ERROR RESOLUTION", 17);
		exit(-1);
	}
	map->r[0] = ft_atoi(s.strs[1]);
	map->r[1] = ft_atoi(s.strs[2]);
	mlx_get_screen_size(NULL, &w, &h);
	if (map->r[0] > w)
		map->r[0] = w;
	if (map->r[1] > h)
		map->r[1] = h;
	return (GOOD);
}

void	check_color(t_strs cf)
{
	if (ft_number_cmp(cf.strs[0], "256") >= 0
		|| ft_number_cmp(cf.strs[1], "256") >= 0
		|| ft_number_cmp(cf.strs[2], "256") >= 0
		|| ft_atoi(cf.strs[0]) < 0
		|| ft_atoi(cf.strs[1]) < 0
		|| ft_atoi(cf.strs[2]) < 0)
	{
		write(1, "ERROR: COLOR\n", 14);
		exit(-1);
	}
}

void	check_c_f(t_map *map, int flag)
{
	if (flag == 1)
		if (map->f != -1)
		{
			write(1, "ERROR FLOOR", 12);
			exit(-1);
		}
	if (flag == 2)
		if (map->c != -1)
		{
			write(1, "ERROR CEILING", 14);
			exit(-1);
		}
}

int		ft_floor(t_strs s, t_map *map)
{
	size_t		i;
	size_t		cc;
	t_strs		cf;

	i = 0;
	cc = 0;
	check_c_f(map, 1);
	while (s.strs[1][i] != '\0')
	{
		if (s.strs[1][i] && ft_chr_find(",", s.strs[1][i++]))
			cc++;
	}
	if (cc != 2)
		return (ERROR);
	if (!(cf.strs = ft_split(s.strs[1], ',')))
		return (ERROR);
	check_color(cf);
	map->f = (ft_atoi(cf.strs[0]) * 65536 +
		ft_atoi(cf.strs[1]) * 256 +
			ft_atoi(cf.strs[2]));
	free_strs(&cf.strs);
	return (GOOD);
}

int		ft_ceiling(t_strs s, t_map *map)
{
	size_t		i;
	size_t		cc;
	t_strs		color;

	i = 0;
	cc = 0;
	check_c_f(map, 2);
	while (s.strs[1][i] != '\0')
	{
		if (ft_chr_find(",", s.strs[1][i++]))
			cc++;
	}
	if (cc != 2)
		return (ERROR);
	if (!(color.strs = ft_split(s.strs[1], ',')))
		return (ERROR);
	check_color(color);
	map->c = (ft_atoi(color.strs[0]) * 65536
		+ ft_atoi(color.strs[1]) * 256
			+ ft_atoi(color.strs[2]));
	free_strs(&color.strs);
	return (TRUE);
}
