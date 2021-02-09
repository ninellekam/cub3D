/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:50:19 by yzena             #+#    #+#             */
/*   Updated: 2021/01/27 17:09:30 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_calloc(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

// char	*ft_strchr(const char *s, int c)
// {
// 	char	*str;

// 	str = (char *)s;
// 	while (*str != c)
// 	{
// 		if (*str == '\0')
// 		{
// 			return (NULL);
// 		}
// 		str++;
// 	}
// 	return (str);
// }
