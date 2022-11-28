/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:55:49 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/22 12:31:14 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
	void *dataref, int (*cmp)())
{
	while (begin_list)
	{
		if (cmp(begin_list->data, dataref) == 0)
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
