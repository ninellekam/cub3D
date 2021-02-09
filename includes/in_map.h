/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:58:41 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/02 17:43:19 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_MAP_H
# define IN_MAP_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "header_map.h"
# include "get_next_line.h"
# include "parsing_utils_1.h"
# include "libft.h"
# include "parse_rfc.h"
# include "parse_is.h"

# define ERROR -1
# define BAD 0
# define GOOD 1

static int	not_1_not_space(char c);
static int	is_border(char **map, size_t i, size_t j);
static int	walls(char **maze, size_t i, size_t j);
static int	walls_spaces(char **maze, size_t i, size_t j);
int			is_closed_map(char **map);
static int	check_position_player(char **maze);
int			valid_map(t_map *map);

int			in_map(char *line, t_map *map);

#endif