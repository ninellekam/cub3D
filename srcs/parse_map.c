/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:38 by yzena             #+#    #+#             */
/*   Updated: 2021/02/20 23:02:57 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_line(t_strs s, char *line, t_map *map, int *fl)
{
	int check;

	*fl = 0;
	if ((s.strs = ft_split((const char*)line, ' ')) == NULL)
		return (ERROR);
	s.len = ft_strs_len(s.strs);
	if ((check = parse_initialize(s, map)) == ERROR)
		return (ERROR);
	check = in_map(line, map);
	if (check == FALSE && s.len > 0)
		check = ERROR;
	if (ft_strlen(line) != 0)
		*fl = 1;
	free(line);
	line = NULL;
	free_strs(&s.strs);
	return (GOOD);
}

void	init_strs(t_strs *s)
{
	s->len = 0;
	s->strs = NULL;
}

int		parse_map(int fd, t_map *map)
{
	char		*line;
	int			check;
	t_strs		s;
	int			fl;

	check = 1;
	init_strs(&s);
	while (get_next_line(fd, &line) > 0)
		check = parse_line(s, line, map, &fl);
	if (fl == 1)
		check = parse_line(s, line, map, &fl);
	return (check);
}

int		delete_empty(t_map *map)
{
	char	**local_map;
	t_strs	ok;
	int		len;

	local_map = map->map;
	while (empty_lines(*local_map) == GOOD)
	{
		free(*(local_map));
		local_map++;
	}
	len = ft_strs_len(local_map);
	if (!(ok.strs = (char **)malloc(sizeof(char *) * (len + 1))))
		return (ERROR);
	ok.strs[len] = 0;
	while (len--)
		ok.strs[len] = local_map[len];
	free(map->map);
	map->map = ok.strs;
	return (GOOD);
}

int		parse_file(char *file_name, t_map *map)
{
	int		fd;
	int		check;

	if ((fd = ft_open_file(file_name)) == ERROR)
		return (ERROR);
	if ((check = parse_map(fd, map)) == ERROR)
	{
		write(1, "ERROR PARSE FILE\n", 17);
		return (ERROR);
	}
	if (map->map == NULL)
	{
		write(1, "ERROR: not map\n", 16);
		return (ERROR);
	}
	check = delete_empty(map);
	if ((check = init_check(map)) == ERROR)
	{
		write(1, "ERROR: INIT ERROR\n", 18);
		return (ERROR);
	}
	if ((check = valid_map(map)) == ERROR)
		return (ERROR);
	ft_close(fd);
	return (TRUE);
}
