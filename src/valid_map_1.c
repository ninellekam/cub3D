/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:38:18 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 14:43:48 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	len_j(char **map, int i, int j)
{
	if (((int)ft_strlen(map[i + 1]) + 1 < j)
		|| (int)ft_strlen(map[i - 1]) + 1 < j)
		return (ERROR);
	return (GOOD);
}

int	valid_1(char **map, int i, int j)
{
	int check;

	check = GOOD;
	if (!(ft_strchr("NSWE 012", map[i][j])))
		return (ERROR);
	check = check_space(map, i, j);
	if (map[i][j] == '0')
	{
		if (map[i + 1][j] == ' ' || map[i + 1][j] == '\0'
			|| map[i][j + 1] == ' '
			|| map[i - 1][j] == ' ' || map[i][j - 1] == ' '
			|| map[i][j + 1] == '\0' || map[i - 1][j] == '\0'
			|| map[i][j - 1] == '\0')
			return (ERROR);
		check = len_j(map, i, j);
	}
	return (check);
}

int	valid_0(char **map, int res)
{
	int	i;
	int	j;
	int check;

	i = -1;
	while (++i < res - 1)
	{
		j = 1;
		if (!(ft_strchr("1 ", map[i][0])))
			return (ERROR);
		while (map[i][j + 1])
		{
			if (valid_1(map, i, j++) == ERROR)
				return (ERROR);
		}
		if (!(ft_strchr("1 ", map[i][j])))
			return (ERROR);
	}
	if ((check = check_frame(map[i], &j)) == ERROR)
		return (ERROR);
	j = -1;
	while ((map[res - 1]) && map[res - 1][++j])
		if (!(ft_strchr("1 ", map[res - 1][j])))
			return (ERROR);
	return (GOOD);
}
