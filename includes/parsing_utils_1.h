#ifndef PARSING_UTILS_1_H
# define PARSING_UTILS_1_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"
# include "header_map.h"

// int		ft_number_cmp(char *nb1, char *nb2);
char		*ft_chr_find(const char *s, int c);
int			ft_is_digit(const char *s, char c);
int			ft_number_cmp(const char *nb1, const char *nb2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(int c);

#endif
