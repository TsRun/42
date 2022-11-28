/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:55:49 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/23 16:13:15 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_rmv(t_list **begin,
	t_list *prec, t_list *supp, void (*free_fct)(void *))
{
	if (supp == *begin)
	{
		*begin = supp->next;
		prec = *begin;
	}
	else
		prec->next = supp->next;
	free_fct(supp->data);
	free(supp);
	return (prec);
}

void	ft_list_remove_if(t_list **begin_list, void *dataref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prec;
	t_list	*after;

	after = *begin_list;
	prec = 0;
	while (after)
	{
		if (cmp(after->data, dataref) == 0)
		{
			prec = ft_list_rmv(begin_list, prec, after, free_fct);
			after = prec;
		}
		else
		{
			prec = after;
			after = after->next;
		}
	}
}
