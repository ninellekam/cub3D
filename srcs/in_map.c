/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:38 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 00:22:42 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			back_to_map_line(char ***map, char *s)
{
	char	**strs;
	size_t	len;

	if (!(map))
		return (ERROR);
	if (!(s))
		return (ERROR);
	len = ft_strs_len(*map);
	strs = (char**)malloc(sizeof(char*) * (len + 2));
	strs[len + 1] = NULL;
	strs[len] = s;
	while (len-- != 0)
		strs[len] = (*map)[len];
	free(*map);
	*map = strs;
	return (GOOD);
}

static int	if_rfcnswe(char *line)
{
	size_t			i;

	if (line == NULL || !(ft_strcmp(line, "\0")))
		return (ERROR);
	i = 0;
	while (line[i] != '\0')
	{
		if (!(ft_strchr(" 012NSEW", line[i])))
			return (ERROR);
		i++;
	}
	return (GOOD);
}

int			in_map(char *line, t_map *map)
{
	if ((if_rfcnswe(line)) != ERROR)
	{
		if (back_to_map_line(&(map->map), ft_strdup(line)) == ERROR)
			return (ERROR);
	}
	else
		return (ERROR);
	return (GOOD);
}
