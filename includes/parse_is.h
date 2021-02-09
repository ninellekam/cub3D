#ifndef PARSE_IS_H
# define PARSE_IS_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "parse_map.h"
# include "header_map.h"
# include "libft.h"
# include "parsing_utils_1.h"

# define ERROR -1
# define GOOD 1
# define BAD 0

int		is_resolution(const char *s);
int		is_floor(const char *s);
int		is_ceiling(const char *s);
int		is_no(const char *s);
int		is_so(const char *s);
int		is_ea(const char *s);
int		is_we(const char *s);
int		is_s(const char *s);

#endif
