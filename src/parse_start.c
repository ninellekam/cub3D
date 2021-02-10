/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:09:58 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/02 17:46:51 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_map.h"
#include "parse_map.h"
#include "game.h"

void	init_map(t_map *map)
{
	map->R[0] = 600;
	map->R[1] = 600;
	map->NO = 0;
	map->SO = 0;
	map->WE = 0;
	map->EA = 0;
	map->S = 0;
	map->F = -1;
	map->C = -1;
	map->map = 0;
}

int main()
{
	t_map *map;
	t_map a;
	int check;
	int i = 0;

	map = &a;
	init_map(map);
	parse_map("map.cub", map);
	game_start(map);
	return (0);
}