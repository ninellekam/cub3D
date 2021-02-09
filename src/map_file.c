/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:57:01 by ninakamkia        #+#    #+#             */
/*   Updated: 2021/01/27 17:19:09 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_file.h"

static int		check_valid_file_name(char *file)
{
	size_t	len;

	if (file == NULL)
		return (ERROR);
	len = ft_strlen(file);
	if (len < 4)
	{
		write(2, "ERROR: NOT VALID MAP\n", 21);
		return (ERROR);
	}
	while (len-- != 0)
	{
		if (file[len] == '.')
		{
			if (ft_strcmp(file + len, ".cub") == 0)
				return (1);
		}
	}
	write(2, "ERROR: not valid map\n", 21);
	return (ERROR);
}

int				ft_open_file(char *file_name)
{
	int	fd = -1;

	if (check_valid_file_name(file_name) == ERROR)
		return (ERROR);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		write(1, "can't open file", 15);
		return (ERROR);
	}
	printf("open file\n");
	if (fd < 0)
		return (ERROR);
	return (fd);
}

int	ft_close(int fd)
{
	if (close(fd) < 0)
		return (ERROR);
	return (1);
}
