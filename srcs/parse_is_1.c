/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_is_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:30:33 by yzena             #+#    #+#             */
/*   Updated: 2021/02/16 13:10:15 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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
