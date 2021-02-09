/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:03:50 by yzena             #+#    #+#             */
/*   Updated: 2020/11/04 13:54:04 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t count;

	if (n == 0)
		return (0);
	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0' && count < n - 1)
	{
		count++;
	}
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
