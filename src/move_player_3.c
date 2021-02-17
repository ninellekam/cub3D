/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:24:41 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 20:45:13 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		button_a_y(t_game *game)
{
	t_double_vec		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)(player->pos.y - plane->y * ROTATE)]
			[(int)player->pos.x] == '0' ||
			is_player(maze[(int)(player->pos.y - plane->y * ROTATE)]
				[(int)player->pos.x]));
}

int		button_a_x(t_game *game)
{
	t_double_vec		*plane;
	t_player			*player;
	char				**maze;

	plane = &game->ray.plane;
	player = &game->player;
	maze = game->map.map;
	return (maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * ROTATE)] == '0'
			|| is_player(maze[(int)player->pos.y]
			[(int)(player->pos.x - plane->x * ROTATE)]));
}

void	crab_left(t_game *game)
{
	if (button_a_x(game))
		game->player.pos.x -= game->ray.plane.x * ROTATE;
	if (button_a_y(game))
		game->player.pos.y -= game->ray.plane.y * ROTATE;
}

void	crab_right(t_game *game)
{
	if (game->map.map[(int)game->player.pos.y]
			[(int)(game->player.pos.x + game->ray.plane.x * ROTATE)] == '0' ||
			is_player(game->map.map[(int)game->player.pos.y]
			[(int)(game->player.pos.x + game->ray.plane.x * ROTATE)]))
		game->player.pos.x += game->ray.plane.x * ROTATE;
	if (game->map.map[(int)(game->player.pos.y
		+ game->ray.plane.y * ROTATE)]
		[(int)game->player.pos.x] == '0'
		|| is_player(game->map.map[(int)(game->player.pos.y
		+ game->ray.plane.y * ROTATE)]
		[(int)game->player.pos.x]))
		game->player.pos.y += game->ray.plane.y * ROTATE;
}
