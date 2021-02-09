#ifndef MAP_FILE_H
# define MAP_FILE_H

# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"
# include "parsing_utils_1.h"
# include "header_map.h"


# define ERROR -1

int				ft_open_file(char *file_name);
int				ft_close(int fd);
static int		check_valid_name_file(char *file);
static int		check_valid_file_name(char *file);

#endif
