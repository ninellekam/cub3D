/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_is_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:29 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 13:10:12 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			is_no(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "NO")))
		return (GOOD);
	return (BAD);
}

int			is_so(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "SO")))
		return (GOOD);
	return (BAD);
}

int			is_ea(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "EA")))
		return (GOOD);
	return (BAD);
}

int			is_we(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "WE")))
		return (GOOD);
	return (BAD);
}

int			is_s(const char *s)
{
	int check;

	if (s == NULL)
		return (BAD);
	if (!(check = ft_strcmp(s, "S")))
		return (GOOD);
	return (BAD);
}
