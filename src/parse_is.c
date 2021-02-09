/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 13:55:39 by yzena             #+#    #+#             */
/*   Updated: 2021/01/25 20:18:35 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_is.h"
#include "parsing_utils_1.h"

int			is_resolution(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "R")))
		return (GOOD);
	return (BAD);
}

int			is_floor(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "F")))
		return (GOOD);
	return (BAD);
}

int			is_ceiling(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "C")))
		return (GOOD);
	return (BAD);
}

int		is_no(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "NO")))
		return (GOOD);
	return (BAD);
}

int		is_so(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "SO")))
		return (GOOD);
	return (BAD);
}

int		is_ea(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "EA")))
		return (GOOD);
	return (BAD);
}

int		is_we(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "WE")))
		return (GOOD);
	return (BAD);
}

int		is_s(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "S")))
		return (GOOD);
	return (BAD);
}
