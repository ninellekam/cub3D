/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:32:52 by yzena             #+#    #+#             */
/*   Updated: 2021/01/27 18:02:48 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_map.h"
#include "get_next_line.h"
#include "libft.h"
#include "parse_map.h"

char	*ft_strs_addback(char ***begin_arr, char *s)
{
	char	**res;
	size_t	len;

	if (begin_arr == NULL || s == NULL)
		return (NULL);
	len = ft_strs_len(*begin_arr) + 1;
	res = (char**)malloc(sizeof(char*) * (len + 1));
	res[len--] = NULL;
	res[len] = s;
	while (len-- != 0)
	{
		res[len] = (*begin_arr)[len];
	}
	free(*begin_arr);
	*begin_arr = res;
	return (s);
}

static int	have_is_nothing(char *line)
{
	size_t			i;

	if (line == NULL)
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
	int check;

	check = have_is_nothing(line);
	if ((check))
	{

		if (ft_strs_addback(&(map->map), ft_strdup(line)) == NULL)
			return (ERROR);
	else
		return (ERROR);
	}
	return (GOOD);
}