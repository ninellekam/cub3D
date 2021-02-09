/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzena <yzena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:12:06 by yzena             #+#    #+#             */
/*   Updated: 2020/11/04 14:44:35 by yzena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst != NULL)
		while (*lst)
		{
			tmp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
}
