/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:08 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 16:24:03 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				ft_open_file(char *file_name)
{
	int	fd;

	fd = -1;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "can't open file", 15);
		return (ERROR);
	}
	if (fd < 0)
		return (ERROR);
	return (fd);
}

int				ft_close(int fd)
{
	if (close(fd) < 0)
		return (ERROR);
	return (1);
}
