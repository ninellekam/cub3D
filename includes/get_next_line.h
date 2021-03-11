/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:05:35 by yzena             #+#    #+#             */
/*   Updated: 2021/01/24 18:28:37 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# define BUFFER_SIZE 1

int		parsing_str(int fd, char **line, char **str);
int		get_next_line(const int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_calloc(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);
// int		ft_strlen(const char *str);
int		err_all(int fd, char **line, char **buf);
int		err_red(int red, char **buf);
#endif
