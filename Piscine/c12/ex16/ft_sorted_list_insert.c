/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:25:16 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 01:12:46 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*e;

	if (!*begin_list || cmp(data, (*begin_list)->data) <= 0)
	{
		e = ft_create_elem(data);
		if (!e)
			return ;
		e->next = *begin_list;
		*begin_list = e;
	}
	else
		ft_sorted_list_insert(&(*begin_list)->next, data, cmp);
}
