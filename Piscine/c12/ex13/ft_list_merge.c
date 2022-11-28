/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:33:55 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/23 16:20:03 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*elem;

	elem = *begin_list1;
	if (!elem)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = begin_list2;
}
