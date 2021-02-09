/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 17:37:14 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/06 17:02:17 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_map.h"
#include "header_map.h"
#include "libft.h"
#include "parsing_utils_1.h"

static int	not_1_not_space(char c)
{
	if (ft_chr_find(" 1", c) == NULL && c != '\0')
		return (GOOD);
	else
		return (BAD);
}

static int	is_border(char **map, size_t i, size_t j)
{
	if (i == 0 || j == 0 || map[i][j + 1] == '\0' || map[i + 1] == NULL)
		return (GOOD);
	return (BAD);
}

static int	walls(char **maze, size_t i, size_t j)
{
	size_t	len_bottom_line;
	size_t	len_upper_line;

	len_bottom_line = ft_strlen(maze[i + 1]);
	len_upper_line = ft_strlen(maze[i - 1]);
	if (len_bottom_line == 0 || len_bottom_line - 1 < j)
	{
		printf("bottom line\n");
		return (BAD);
	}
	if (len_upper_line == 0 || len_upper_line - 1 < j)
	{
		printf("upper line\n");
		return (BAD);
	}
	if (maze[i][j + 1] == '\0' || maze[i][j + 1] == ' ')
	{
		printf("right [j+1] == 0 or space\n");
		return (BAD);
	}
	if (maze[i + 1][j] == '\0' || maze[i + 1][j] == ' ')
	{
		printf("bottom [j] == 0 or space\n");
		return (BAD);
	}
	return (GOOD);
}

static int	walls_spaces(char **maze, size_t i, size_t j)
{
	size_t	len;

	if (maze[i + 1] == NULL)
	{
		if (not_1_not_space(maze[i][j + 1]))
			return (BAD);
		return (GOOD);
	}
	len = ft_strlen(maze[i + 1]);
	if (len == 0 || len - 1 < j)
	{
		if (not_1_not_space(maze[i][j + 1]))
			return (BAD);
		return (GOOD);
	}
	if (not_1_not_space(maze[i + 1][j])
	|| not_1_not_space(maze[i][j + 1]))
		return (BAD);
	return (GOOD);
}

int			is_closed_map(char **map)
{
	size_t		j;
	size_t		i;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j])
		{
			if (not_1_not_space(map[i][j]))
			{
				if (is_border(map, i, j))
					return (BAD);
				if (!(walls(map, i, j)))
					return (BAD);
			}
			if (ft_isspace(map[i][j]))
			{
				if (is_border(map, i, j))
				{
					printf("is_border\n");
					return (BAD);
				}
				if (!(walls_spaces(map, i, j)))
				{
					printf("!wall_spaces");
					return (BAD);
				}
			}
		}
	}
	return (GOOD);
}

// static int	scan_map_empty_lines(char **maze)
// {
// 	size_t	y;

// 	y = 0;
// 	while (maze[y] != NULL)
// 	{
// 		if (maze[y][0] == '\0')
// 			return (GOOD);
// 		y++;
// 	}
// 	return (BAD);
// }

static int	check_position_player(char **map)
{
	size_t	player_count;
	size_t	x;
	size_t	y;

	if (map == NULL)
		return (BAD);
	player_count = 0;
	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (ft_strchr("NSEW", map[y][x]) != NULL && is_border(map, y, x))
				return (BAD);
			if (ft_strchr("NSEW", map[y][x]) != NULL)
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count == 1)
		return (GOOD);
	return (BAD);
}

int			valid_map(t_map *map)
{
	if (!(map))
		return (ERROR);
	if (!(check_position_player(map->map)))
	{
		printf("ERROR: NOT VAID MAP (position player)\n");
		return (ERROR);
	}
	else
		printf("MAP IS GOOD\n");
	if (is_closed_map(map->map) != GOOD)
	{
		printf("ERROR: NOT VAID MAP\n");
		return (ERROR);
	}
	else
		printf("MAP IS GOOD\n");
	return (GOOD);
}
