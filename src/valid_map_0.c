/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:31:15 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 17:12:22 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	check_space(char **map, int i, int j)
{
	if (map[i][j] == ' ')
	{
		if (map[i][j + 1] != ' ' && map[i][j + 1]
		!= '1' && map[i][j + 1] != '\0')
		{
			write(1, "Problem: space not with 1 or space (right)\n", 40);
			return (ERROR);
		}
		if (map[i + 1])
		{
			if (map[i + 1][j])
				if ((ft_strlen(map[i + 1])) < j)
					if (map[i + 1][j] != ' ' && map[i + 1][j]
					!= '1' && map[i + 1][j] != '\0')
					{
						write(1, "Problem: space not w 1 or ' ' (down)\n", 37);
						return (ERROR);
					}
		}
	}
	return (GOOD);
}

int	check_frame(char *str, int *j)
{
	*j = 0;
	while (str[*j] == ' ')
		(*j)++;
	while (str[*j] == '1')
		(*j)++;
	if (str[*j] == '\0')
		return (ERROR);
	return (GOOD);
}

int	check_map(char **map)
{
	int	i;
	int	j;
	int	res;

	j = 0;
	i = 0;
	res = 0;
	while (map[res])
		res++;
	while ((map[i]) && map[i][j])
	{
		if (!(ft_strchr("1 ", map[i][j])))
			return (ERROR);
		j++;
	}
	return (valid_0(map, res));
}

int	check_pos_player(char **map)
{
	size_t	player_count;
	size_t	j;
	size_t	i;

	if (map == NULL)
		return (BAD);
	player_count = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSEW", map[i][j]) != NULL)
				player_count++;
			j++;
		}
		i++;
	}
	if (player_count == 1)
		return (GOOD);
	return (BAD);
}

int	valid_map(t_map *map)
{
	if (!(map))
		return (ERROR);
	if (!(check_pos_player(map->map)))
	{
		write(1, "ERROR: NOT VALID MAP (position player)\n", 39);
		return (ERROR);
	}
	else
		printf("MAP IS GOOD\n");
	if (check_map(map->map) != GOOD)
	{
		write(1, "ERROR: NOT VALID MAP (check)\n", 29);
		return (ERROR);
	}
	else
		write(1, "MAP IS GOOD\n", 12);
	return (GOOD);
}
