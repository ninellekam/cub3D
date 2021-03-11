/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:39:01 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 15:02:15 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "mlx.h"
#include <math.h>
#include "header_map.h"
#include "libft.h"
#include <fcntl.h>
# define ERROR -1
# define GOOD	1
# define ROTATE 0.1
# define ROTSPEED 0.05
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
//---------------- vectors --------------------------------------------------

typedef struct			s_double_vec
{
	double				x;
	double				y;
}						t_double_vec;

typedef struct			s_int_vec
{
	int					x;
	int					y;
}						t_int_vec;


// ---------------------- mlx ----------------------------------

typedef struct			s_mlx
{
    void				*win;
    void				*mlx;
}						t_mlx;

// ---------------------- image -------------------------
typedef struct			s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}                       t_img;

// ------------ player ------------------------------

typedef struct			s_player
{
	t_double_vec		pos;
	t_double_vec		dir;
	char				start_view;
}						t_player;

// ----------------------------- ray - луч -----------------------
typedef struct			s_ray
{
	t_double_vec		plane;
	double				camera_x;
	t_double_vec		dir;
	t_int_vec			map;
	t_double_vec		side_d;
	t_double_vec		delta;
	double				perp_wall_dist;
	t_int_vec			step;
	int					hit;
	int					side;
	int					line_h;
	int					draw_start;
	int					draw_end;
}						t_ray;

typedef struct			s_tex2 {
	void				*img;
	int					*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					wdt;
	int					hgt;
}						t_tex2;

typedef struct			s_t
{
	char				*relative_path;
	t_tex2				img;
	int					X;
	int					Y;
}						t_t;

typedef struct			s_tex
{
	t_t					NO;
	t_t					SO;
	t_t					WE;
	t_t					EA;
}						t_tex;

typedef struct			s_tex_draw_vars
{
	t_t					*tex;
	int					tex_num;
	double				wall_x;
	int					tex_x;
	double				step;
	double				tex_pos;
	int					color;
	int					tex_y;
}						t_tex_draw_vars;

typedef struct			s_button
{
	char				w;
	char				s;
	char				a;
	char				d;
	char				left;
	char				right;
}						t_button;

typedef struct			s_sprites
{
	size_t				nums;
	t_double_vec		**sprite;
	int					*order;
	double				*distant;
	t_t					tex;
	double				spriteX;
	double				spriteY;
	double				transformX;
	double				transformY;
	int					screenX;
	double				lyambda;
	int					s_h;
	int					s_w;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
	int					texX;
	int					texY;
	int					ok;
	int					color;
	size_t				hi;
}						t_sprites;

// -------------------------- game ----------------------
typedef struct			s_game
{
    t_mlx				mlx;
	t_img				img;
	t_tex				tex;
	t_player			player;
	t_button			button;
	t_map				map;
	t_ray				ray;
	t_sprites			sprites;
}						t_game;



void	game_start(t_map *map, char *argv, char *file_name);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

//------------- i n i t  s t a r t--------------------------------------------------
int			init_win(t_mlx *mlx, t_map *map);
void		init_win_img(t_mlx *mlx, t_img *img, t_map *map);
void		init_game_s_player_button(t_game *g, t_img *img, t_mlx *mlx, t_map *map);

int			init_ray_0(t_game *game, size_t i);
int			init_ray_1(t_ray *ray, t_player *player);
void		ray(t_game *game);
void		init_side_hit(t_ray *ray, char **mymap);
void		init_perp_wall_dist(t_game *game);

int			raycasting_render(t_game *game);
int			init_img(t_img *img, t_mlx *mlx, t_map *map);

void		draw_tex(t_game *game, size_t i);
static void	init_vars(t_game *game, t_tex_draw_vars *vars);
static t_t	*init_tex(t_game *game);

//---------------- i n i t   p l a y e r------------------------------------
int			init_player(t_player *player, t_double_vec *plane, char **maze);
static int	direction_north_south(t_player *player, t_double_vec *plane);
static int	direction_east_west(t_player *player, t_double_vec *plane);
static int	player_pos(t_player *player, char **maze);
int			is_player(char c);

// --------- t e x t u r e s -----------------------------------------------------
void		init_tex_sides(t_game *game);
void		init_relative_path(t_tex *texture, t_map *map);
int			valid_xpm(char *s);
int			init_img_ea_tex(void *mlx, t_tex *texture);
int			init_img_we_tex(void *mlx, t_tex *texture);
int			init_img_no_tex(void *mlx, t_tex *texture);
int			init_img_so_tex(void *mlx, t_tex *texture);

//------------------- b u t t o n ----------------------------------------------
int			button_pressed(int keycode, t_game *game);
int			button_unpressed(int keycode, t_game *game);

static int	is_zero(t_button *but);
void		is_wall_front(t_game *game);
void		is_wall_backward(t_game *game);

//--------------------- s p r i t e s ----------------------------------------
void		ft_sprite(t_game *g, double *buf);
int			sprites_num(t_game *game);
void		init_array_sprites(t_game *game, size_t nums, int x, int y);
void		sprites_array(t_game *game, size_t nums, int x, int y);
void		init_sprites(t_game *game);
void		draw_sprites(t_game *game);
void		sprite_draw_x(t_game *game);
void		sprite_draw_x(t_game *game);
void		sprite_draw_y(t_game *game);
void		quick_sort(int *order, double *distance, size_t len);

int			ft_strcmp(const char *s1, const char *s2);
void		move_player(t_game *game);
void		init_button(t_button *but);
int			raycasting_render_one_frame(t_game *game);

// ------------------- b m p -----------------------------------------------
int			ft_bmp(char *name, t_game  *game);
void		ft_header(int fd, t_game *game);

void	crab_right(t_game *game);
void	crab_left(t_game *game);

int		finish_game(t_game *game);
void	free_strs(char ***strs);
int		free_map(t_map *map);
int		init_check(t_map *map);
int		free_sprites(t_double_vec ***sprites);
int		check_format_cub(char *str);
int		ft_number_cmp(const char *nb1, const char *nb2);

#endif
