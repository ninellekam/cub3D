/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:49:16 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/02 17:46:46 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_map.h"

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

static int	line_parse(char *line, t_map *map)
{
	t_strs		s;
	int			check;
	int			len;
	int i;

	i = 0;
	if ((s.strs = ft_split((const char*)line, ' ')) == NULL)
		return (ERROR);
	s.len = ft_strs_len(s.strs);
	check = parse_initialize(s, map);
	// if (check == TRUE)
		check = in_map(line, map);
	if (check == FALSE && s.len > 0)
		check = ERROR;
	return (check);
}

int parse_file(int fd, t_map *map)
{
	char	*line;
	int		check;

	check = 1;
	while (get_next_line(fd, &line) > 0)
	{
		check = line_parse(line, map);
		free(line);
		line = NULL;
	}
	return (check);
}

int	empty_lines(char *s)
{
	char	empty_status;

	if (s == NULL)
		return (GOOD);
	if (*s == '\0')
		return (GOOD);
	empty_status = BAD;
	while (*s != '\0')
	{
		// if (ft_strchr("012NSEW", *s) != NULL)
		if (ft_strchr("./CFRA", *s) != NULL)
			return (GOOD);
		s++;
	}
	return (empty_status);
}

int	without_empty_lines(t_map *map)
{
	char 	**local_map;
	t_strs	ok;
	int		len;

	local_map = map->map; // char **
	while (empty_lines(*local_map) == GOOD)
	{
		free(*(local_map)); // char * string
		local_map++;
	}
	len = ft_strs_len(local_map);
	ok.strs = (char **)malloc(sizeof(char *) * (len + 1));
	ok.strs[len] = 0;
	while (len--)
	{
		ok.strs[len] = local_map[len];
		// printf("%s\n", ok.strs[len]);
	}
	free(map->map);
	map->map = ok.strs;
	return (GOOD);
}

int			parse_map(char *file_name, t_map *map)
{
	int		fd;
	int		status;

	if ((fd = ft_open_file(file_name)) == ERROR)
		return (ERROR);
	parse_file(fd, map);
	without_empty_lines(map);
	valid_map(map);
	ft_close(fd);
	return (TRUE);
}
