/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:55 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 13:10:31 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_chr_find(const char *s, int c)
{
	unsigned char *cs;

	cs = (unsigned char*)s;
	while (*cs != '\0')
	{
		if (*cs == (unsigned char)c)
			return ((char*)cs);
		cs++;
	}
	if (c == 0)
		return ((char*)cs);
	return (NULL);
}

int		ft_is_digit(const char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

int		ft_number_cmp(const char *nb1, const char *nb2)
{
	size_t	nb1_len;
	size_t	nb2_len;

	if (nb1 == NULL && nb2 != NULL)
		return (-1);
	if (nb1 != NULL && nb2 == NULL)
		return (1);
	if (nb1 == NULL && nb2 == NULL)
		return (0);
	nb1_len = ft_strlen(nb1);
	nb2_len = ft_strlen(nb2);
	if (nb1_len < nb2_len)
		return (-1);
	if (nb1_len > nb2_len)
		return (1);
	while (*nb1 != '\0' && *nb2 != '\0')
	{
		if (*nb1 != *nb2)
			return (*nb1 - *nb2);
		nb1++;
		nb2++;
	}
	return (*nb1 - *nb2);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL && s2 != NULL)
		return (-1);
	if (s1 != NULL && s2 == NULL)
		return (1);
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int		ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}
