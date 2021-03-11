/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:50 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 17:13:38 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "game.h"

size_t	ft_strs_len(char **s)
{
	size_t len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != NULL)
		len++;
	return (len);
}

void	init_map(t_map *map)
{
	map->R[0] = -1;
	map->R[1] = -1;
	map->NO = 0;
	map->SO = 0;
	map->WE = 0;
	map->EA = 0;
	map->S = 0;
	map->F = -1;
	map->C = -1;
	map->map = 0;
}

int		check_format_cub(char *str)
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
		if (!(ft_strcmp(str + i, ".cub")))
			return (GOOD);
		i++;
	}
	return (ERROR);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_map	a;
	int		check;

	map = &a;
	init_map(map);
	if ((check = check_format_cub(argv[1])) == ERROR)
		return (0);
	if ((check = parse_map(argv[1], map)) == ERROR)
		return (0);
	game_start(map, argv[2], argv[1]);
	return (0);
}
