/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:17:00 by yzena             #+#    #+#             */
/*   Updated: 2021/02/17 22:32:04 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	unsigned int	pos;
	unsigned int	i;

	if (!*needle)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && str[pos + i] == needle[i] &&
				(size_t)(pos + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}
