/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:26:36 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/02/21 13:26:57 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include <math.h>
# include "header_map.h"
# include "libft.h"
# include <fcntl.h>
# define ERROR -1
# define GOOD 1
# define ROTATE 0.1
# define ROTSPEED 0.05
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

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

typedef struct			s_mlx
{
	void				*win;
	void				*mlx;
}						t_mlx;

typedef struct			s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_img;

typedef struct			s_player
{
	t_double_vec		pos;
	t_double_vec		dir;
	char				start_view;
}						t_player;

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

typedef struct			s_tex2
{
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
	int					width;
	int					height;
}						t_t;

typedef struct			s_tex
{
	t_t					no;
	t_t					so;
	t_t					we;
	t_t					ea;
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
	double				sprite_x;
	double				sprite_y;
	double				transformx;
	double				transformy;
	int					screenx;
	double				lyambda;
	int					s_h;
	int					s_w;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
	int					texx;
	int					texy;
	int					ok;
	int					color;
	int					hi;
}						t_sprites;

typedef struct			s_cub
{
	t_mlx				mlx;
	t_img				img;
	t_tex				tex;
	t_player			player;
	t_button			button;
	t_map				map;
	t_ray				ray;
	t_sprites			sprites;
}						t_cub;

void					cub_start(t_map *map, char *argv, char *file_name);
void					my_mlx_pixel_put(t_img *data, int x, int y, int color);
int						empty_lines(char *s);
int						valid_xpm(char *str);
int						init_win(t_mlx *mlx, t_map *map);
void					init_win_img(t_mlx *mlx, t_img *img, t_map *map);
void					init_cub_s_player_button(t_cub *g,
						t_img *img, t_mlx *mlx, t_map *map);
int						init_ray_0(t_cub *cub, size_t i);
int						init_ray_1(t_ray *ray, t_player *player);
void					ray(t_cub *cub);
void					init_side_hit(t_ray *ray, char **mymap);
void					init_perp_wall_dist(t_cub *cub);
int						raycast(t_cub *cub);
int						init_img(t_img *img, t_mlx *mlx, t_map *map);
void					draw_tex(t_cub *cub, size_t i);
int						init_player(t_player *player,
						t_double_vec *plane, char **maze);
int						direction_north_south(t_player *player,
						t_double_vec *plane);
int						direction_east_west(t_player *player,
						t_double_vec *plane);
int						player_pos(t_player *player, char **maze);
int						is_player(char c);
void					init_tex_sides(t_cub *cub);
void					init_relative_path(t_tex *texture, t_map *map);
int						valid_xpm(char *s);
int						init_img_ea_tex(void *mlx, t_tex *texture);
int						init_img_we_tex(void *mlx, t_tex *texture);
int						init_img_no_tex(void *mlx, t_tex *texture);
int						init_img_so_tex(void *mlx, t_tex *texture);
int						button_pressed(int keycode, t_cub *cub);
int						button_unpressed(int keycode, t_cub *cub);
int						is_zero(t_button *but);
void					is_wall_front(t_cub *cub);
void					is_wall_backward(t_cub *cub);
void					ft_sprite(t_cub *g,
						double *buf);
int						sprites_num(t_cub *cub);
void					init_array_sprites(t_cub *cub,
						size_t nums, int x, int y);
void					sprites_array(t_cub *cub, size_t nums, int x, int y);
void					init_sprites(t_cub *cub);
void					draw_sprites(t_cub *cub);
void					sprite_draw_x(t_cub *cub);
void					sprite_draw_x(t_cub *cub);
void					sprite_draw_y(t_cub *cub);
void					quick_sort(int *order, double *distance, size_t len);
int						ft_strcmp(const char *s1, const char *s2);
void					move_player(t_cub *cub);
void					init_button(t_button *but);
int						raycast_one_frame(t_cub *cub);
int						ft_bmp(char *name, t_cub *cub);
void					ft_header(int fd, t_cub *cub);
void					crab_right(t_cub *cub);
void					crab_left(t_cub *cub);
int						finish_cub(t_cub *cub);
void					free_strs(char ***strs);
int						free_map(t_map *map);
int						init_check(t_map *map);
int						free_sprites(t_double_vec ***sprites);
int						check_format_cub(char *str);
int						ft_number_cmp(const char *nb1, const char *nb2);

#endif
