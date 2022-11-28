/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:39:25 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/23 14:16:51 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*before;
	t_list	*after;

	before = 0;
	while (*begin_list)
	{
		after = (*begin_list)->next;
		(*begin_list)->next = before;
		before = *begin_list;
		*begin_list = after;
	}
	*begin_list = before;
}
