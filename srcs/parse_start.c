/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:50 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "cub.h"

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
	map->r[0] = -1;
	map->r[1] = -1;
	map->no = 0;
	map->so = 0;
	map->we = 0;
	map->ea = 0;
	map->s = 0;
	map->f = -1;
	map->c = -1;
	map->map = NULL;
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
	if (argc != 2 && argc != 3)
	{
		write(1, "ERROR: count of args\n", 22);
		return (0);
	}
	if ((check = check_format_cub(argv[1])) == ERROR)
	{
		write(1, "ERROR\n", 7);
		return (0);
	}
	if ((check = parse_file(argv[1], map)) == ERROR)
		return (0);
	cub_start(map, argv[2], argv[1]);
	return (0);
}
