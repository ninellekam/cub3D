/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:49:11 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/02 17:43:00 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include "parsing_utils_1.h"
# include "get_next_line.h"
# include "map_file.h"
# include "libft.h"
# include "header_map.h"
# include "parse_initialize.h"
# include "in_map.h"

# define ERROR -1
# define TRUE 1
# define FALSE 0

// typedef struct			s_str
// {
// 	char				*str;
// 	size_t				len;
// }						t_str;

// typedef struct			s_strs
// {
// 	char				**strs;
// 	size_t				len;
// }						t_strs;


// typedef	struct			s_map
// {
// 	size_t				R[2];
// 	char				*NO;
// 	char				*SO;
// 	char				*WE;
// 	char				*EA;
// 	char				*S;
// 	int64_t				F;
// 	int64_t				C;
// 	char				**map;
// 	int					(*parse_file)(char *file, struct s_map *map);
// //	int					(*clear)(struct s_map *map);
// //	int					(*scan_error)(struct s_map *map);
// 	void				(*print)(struct s_map *map);
// }						t_map;

int						new_map(t_map *map);
int						parse_map(char *file, t_map *map);
//void					init_zero_map(t_map *map);
int						free_map(t_map *map);
size_t					ft_strs_len(char **s);
#endif
