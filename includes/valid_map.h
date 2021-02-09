#ifndef in_map_H
# define in_map_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"
# include "header_map.h"

char		*ft_strs_addback(char ***begin_arr, char *s);
static int	have_is_nothing(char *line);
int			in_map(char *line, t_map *map);

#endif