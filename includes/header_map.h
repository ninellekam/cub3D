/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_map.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 20:35:45 by yzena             #+#    #+#             */
/*   Updated: 2021/02/20 13:25:57 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_MAP_H
# define HEADER_MAP_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# define ERROR -1
# define BAD 0
# define GOOD 1

typedef struct			s_strs
{
	char				**strs;
	size_t				len;
}						t_strs;

typedef	struct			s_map
{
	int					r[2];
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int64_t				f;
	int64_t				c;
	char				**map;
}						t_map;

int						lets_start_map(t_map *map);
void					init_map(t_map *map);

#endif
