#ifndef PARSE_INITIALIZE_H
# define PARSE_INITIALIZE_H

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

int	parse_initialize(t_strs s, t_map *map);
int	parse_tech(t_strs s, t_map *map);
int	parse_tex_1(t_strs s, t_map *map);
int	parse_tex_2(t_strs s, t_map *map);
// ------------- r c f ------------------------------
int	is_resolution(const char *s);
int	is_floor_color(const char *s);
int	is_ceiling_color(const char *s);
// ----------------- no so we ea s ------------------
int	is_no(const char *s);
int	is_so(const char *s);
int	is_ea(const char *s);
int	is_we(const char *s);
int	is_s(const char *s);
#endif
