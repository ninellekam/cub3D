/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:09:23 by yzena             #+#    #+#             */
/*   Updated: 2021/02/10 13:00:35 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void    sprites_2(t_game *game, size_t i)
{
    t_sprites *s;
    int     *order;
    t_double_vec pos;
    t_double_vec plane;
    t_double_vec dir;

    dir = game->player.dir;
    pos = game->player.pos;
    plane = game->ray.plane;
    s = &game->sprites;
    order = game->sprites.order;
<<<<<<< HEAD
    s->spriteX = s->sprite[order[i]]->x - pos.x;
    s->spriteY = s->sprite[order[i]]->y - pos.y;
    s->lyambda = 1.0 / (plane.x * dir.y - dir.x * plane.y);
    s->transformX = s->lyambda * (dir.y * s->spriteX - dir.x * s->spriteY);
    s->transformY = s->lyambda * (-plane.y * s->spriteX + plane.x * s->spriteY);
    s->screenX = (int)((game->map.R[0] / 2) * (1 + s->transformX / s->transformY));
=======
    s.spriteX = s.sprite[order[i]]->x - pos.x;
    s.spriteY = s.sprite[order[i]]->y - pos.y;
    s.lyambda = 1.0 / (plane.x * dir.y - dir.x * plane.y);
    s.transformX = s.lyambda * (dir.y * s.spriteX - dir.x * s.spriteY);
    s.transformY = s.lyambda * (-plane.y * s.spriteX + plane.x * s.spriteY);
    s.screenX = (int)((game->map.R[0] - game->map.R[0] / 2) *
	(1 + s.transformX / s.transformY));
>>>>>>> master
}

void    sprites_1(t_game *game, size_t nums)
{
    int				*order;
    double			*distant;
    size_t			i = 0;
    t_double_vec    **sprt;
    t_double_vec   pos;

	if (!(order = (int*)malloc(sizeof(int) * nums)))
	{
		printf("ERROR\n");
		return ;
	}
	if (!(distant = (double*)malloc(sizeof(double) * nums)))
	{
		printf("ERROR\n");
		return ;
	}
    pos = game->player.pos;
    sprt = game->sprites.sprite;
	// printf("spr.x%f", sprt[i]->x);
	// printf("spr.y%f", sprt[i]->y);
	// printf("pos.x%f", pos.x);
	// printf("pos.y%f", pos.y);
	// exit(0);
    while (i < game->sprites.nums)
    {
        order[i] = i;
		distant[i] = pow((pos.x - sprt[i]->x), 2);
		distant[i] += pow((pos.y - sprt[i]->y), 2);
        // distant[i] = ((pos.x - sprt[i]->x) * (pos.x - sprt[i]->x) + (pos.y - sprt[i]->y) * (pos.y - sprt[i]->y));
		i++;
    }
    game->sprites.order = order;
    game->sprites.distant = distant;
}

void	sprite_draw_y(t_game *game)
{
	t_sprites	*s;

	s = &game->sprites;
	s->s_h = abs((int)(game->map.R[1] / s->transformY));
	s->s_w = abs((int)(game->map.R[1] / s->transformY));
	s->start_y = -s->s_h / 2 + game->map.R[1] / 2;
	if (s->start_y < 0)
		s->start_y = 0;
	s->end_y = s->s_h / 2 + game->map.R[1] / 2;
	if (s->end_y >= game->map.R[1])
		s->end_y = game->map.R[1] - 1;
}

void    sprite_draw_x(t_game *game)
{
    t_sprites	*s;

	s = &game->sprites;
	s->s_h = abs((int)(game->map.R[1] / s->transformY));
	s->s_w = abs((int)(game->map.R[1] / s->transformY));
    s->start_x = -s->s_w / 2 + s->screenX;
	if (s->start_x < 0)
		s->start_x = 0;
	s->end_x = s->s_w / 2 + s->screenX;
    // if(s->end_x >= game->map.R[0])
    //     s->end_x  = game->map.R[0] - 1;
}

void    sprite_draw(t_game *game)
{
    sprite_draw_x(game);
    sprite_draw_y(game);
}

void    sprites(t_game *game, double *mas)
{
    t_sprites		*sprites;
	size_t					i;

	sprites = &game->sprites;
	i = sprites_num(game);
	sprites_1(game, i);
	quick_sort(sprites->order, sprites->distant, sprites->nums);
 	i = 0;
	while (i < game->sprites.nums)
	{
		sprites_2(game, i);
		sprite_draw(game);
		sprites_3(game, mas);
		i++;
	}
}
