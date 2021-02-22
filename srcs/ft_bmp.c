/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 12:37:31 by yzena             #+#    #+#             */
/*   Updated: 2021/02/21 13:20:26 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

unsigned int	get_color(t_img *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void			init_bmp_1(int fd, t_cub *cub)
{
	int width;
	int height;
	int plane_count;
	int bbp;

	width = cub->map.r[0];
	write(fd, &width, 4);
	height = cub->map.r[1];
	write(fd, &height, 4);
	plane_count = 1;
	write(fd, &plane_count, 2);
	bbp = cub->img.bits_per_pixel;
	write(fd, &bbp, 2);
}

void			init_bmp_0(int fd, t_cub *cub)
{
	long	file_size;
	int		i_size;
	int		offset;
	int		width;

	file_size = 58 + (cub->map.r[0] * cub->map.r[1]) * 4;
	i_size = 58;
	offset = 40;
	width = cub->map.r[0];
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &i_size, 4);
	write(fd, &offset, 4);
}

void			ft_header(int fd, t_cub *cub)
{
	int					i;
	int					j;
	int					color;
	int					count;

	if ((fd = open("screenshot.bmp", O_CREAT
	| O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
		write(1, "ERROR: OPEN BMP\n", 16);
	init_bmp_0(fd, cub);
	init_bmp_1(fd, cub);
	count = -1;
	while (++count < 28)
		write(fd, "\0", 1);
	i = cub->map.r[1] - 1;
	while (i-- > 0)
	{
		j = -1;
		while (++j < (int)cub->map.r[0])
		{
			color = get_color(&(cub->img), j, i);
			if (write(fd, &color, 4) < 0)
				return ;
		}
	}
}

int				ft_bmp(char *name, t_cub *cub)
{
	int		fd;
	t_map	*map;
	t_map	a;

	map = &a;
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		write(1, "ERROR: open file bmp\n", 21);
		return (ERROR);
	}
	ft_header(fd, cub);
	close(fd);
	return (GOOD);
}
