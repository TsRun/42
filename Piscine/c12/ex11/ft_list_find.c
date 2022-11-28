/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:55:49 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/22 12:31:35 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *dataref, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->data, dataref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0);
}
