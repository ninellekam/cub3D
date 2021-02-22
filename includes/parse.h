/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:54:38 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include "get_next_line.h"
# include "libft.h"
# include "cub.h"
# include "header_map.h"

# define ERROR -1
# define TRUE 1
# define FALSE 0
# define GOOD 1
# define BAD 0

int			new_map(t_map *map);
int			parse_file(char *file, t_map *map);
int			free_map(t_map *map);
size_t		ft_strs_len(char **s);
int			ft_resolution(t_strs s, t_map *map);
int			ft_floor(t_strs s, t_map *map);
int			ft_ceiling(t_strs s, t_map *map);
int			is_resolution(const char *s);
int			is_floor(const char *s);
int			is_ceiling(const char *s);
int			is_no(const char *s);
int			is_so(const char *s);
int			is_ea(const char *s);
int			is_we(const char *s);
int			is_s(const char *s);
int			parse_initialize(t_strs s, t_map *map);
int			parse_rfc(t_strs s, t_map *map);
int			parse_no_so_we(t_strs s, t_map *map);
int			parse_ea_s(t_strs s, t_map *map);
int			is_resolution(const char *s);
int			is_floor_color(const char *s);
int			is_ceiling_color(const char *s);
int			is_no(const char *s);
int			is_so(const char *s);
int			is_ea(const char *s);
int			is_we(const char *s);
int			is_s(const char *s);
int			ft_open_file(char *file_name);
int			ft_close(int fd);
int			valid_1(char **map, int i, int j);
int			valid_0(char **map, int res);
int			check_map(char **map);
int			valid_map(t_map *map);
int			in_map(char *line, t_map *map);
int			check_frame(char *str, int *j);
int			check_space(char **map, int i, int j);
char		*ft_chr_find(const char *s, int c);
int			ft_is_digit(const char *s, char c);
int			ft_number_cmp(const char *nb1, const char *nb2);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isspace(int c);
int			back_to_map_line(char ***begin_arr, char *s);
int			in_map(char *line, t_map *map);

#endif
