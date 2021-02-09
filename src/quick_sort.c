/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:21:03 by yzena             #+#    #+#             */
/*   Updated: 2021/02/07 16:49:48 by ninakamkia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	quick_sort(int *order, double *distance, size_t len)
{
	size_t	i;
	size_t	j;
	double	save;

	if (len == 0)
		return ;
	i = -1;
	while (++i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (distance[i] < distance[j])
			{
				save = distance[i];
				distance[i] = distance[j];
				distance[j] = save;
				save = (double)order[i];
				order[i] = order[j];
				order[j] = (int)save;
			}
			j++;
		}
	}
}