/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 21:47:54 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/04 14:30:39 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	is_zero(t_button *but)
{
	return (but->w == 0 && but->s == 0 && but->a == 0 && but->d == 0);
}

void		move_player(t_game *game)
{
	t_player	*player;
	char		**map;

	player = &game->player;
	map = game->map.map;
	if (is_zero(&game->button))
		return ;
	if (game->button.w == 1)
		is_wall_front(game);
	if (game->button.s == 1)
		is_wall_backward(game);
	if (game->button.d == 1)
		rotate_left(game);
	if (game->button.a == 1)
		rotate_right(game);
}
