/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:05:39 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 12:29:11 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	parsing_str(int fd, char **line, char **str)
{
	char	*s_tmp;
	size_t	len;

	len = 0;
	while (str[fd][len])
	{
		if (str[fd][len] == '\n')
		{
			str[fd][len] = '\0';
			*line = ft_strdup(str[fd]);
			s_tmp = ft_strdup(str[fd] + len + 1);
			free(str[fd]);
			str[fd] = s_tmp;
			return (1);
		}
		len++;
	}
	*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}

int	err_red(int red, char **buf)
{
	if (red == -1)
	{
		free(*buf);
		return (-1);
	}
	return (0);
}

int	err_all(int fd, char **line, char **buf)
{
	if (fd < 0 || !(line) || BUFFER_SIZE <= 0 || !(*buf))
	{
		free(*buf);
		return (-1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*str[1024] = {0};
	int			red;
	char		*buf;
	char		*s_tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (err_all(fd, line, &buf) == -1)
		return (-1);
	while ((red = read(fd, buf, BUFFER_SIZE)))
	{
		if (err_red(red, &buf) == -1)
			return (-1);
		buf[red] = '\0';
		if (!str[fd])
			str[fd] = ft_calloc(1);
		s_tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = s_tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (red == 0 && !(str[fd]))
		str[fd] = ft_calloc(1);
	free(buf);
	return (parsing_str(fd, line, str));
}
