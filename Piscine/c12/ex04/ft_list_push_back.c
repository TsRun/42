/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:31 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/24 01:13:03 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*new;

	new = ft_create_elem(data);
	elem = *begin_list;
	if (!elem)
	{
		*begin_list = new;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	elem->next->next = 0;
}
