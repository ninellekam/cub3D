#ifndef PARSE_RFC_H
# define PARSE_RFC_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "parse_map.h"
# include "libft.h"
# include "parsing_utils_1.h"
# include "header_map.h"

# define ERROR -1
# define GOOD 1
# define BAD 0

int	resolution(t_strs s, t_map *map);
int	ft_floor(t_strs s, t_map *map);
int	ceiling(t_strs s, t_map *map);

#endif
