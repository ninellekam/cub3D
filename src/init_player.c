/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:29:53 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:29:55 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	player_pos(t_player *player, char **maze)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (maze[i] != NULL)
	{
		j = 0;
		while (maze[i][j] != '\0')
		{
			if (is_player(maze[i][j]))
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				player->start_view = maze[i][j];
				maze[i][j] = '0';
				return (GOOD);
			}
			j++;
		}
		i++;
	}
	return (BAD);
}

static int	direction_east_west(t_player *player, t_double_vec *plane)
{
	if (player->start_view == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
		plane->x = 0;
		plane->y = -0.66;
	}
	if (player->start_view == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
		plane->x = 0;
		plane->y = 0.66;
	}
	return (0);
}

static int	direction_north_south(t_player *player, t_double_vec *plane)
{
	if (player->start_view == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1;
		plane->x = 0.66;
		plane->y = 0;
	}
	else if (player->start_view == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
		plane->x = -0.66;
		plane->y = 0;
	}
	return (0);
}

int			init_player(t_player *player, t_double_vec *plane, char **maze)
{
	player_pos(player, maze);
	direction_north_south(player, plane);
	direction_east_west(player, plane);
	return (GOOD);
}
