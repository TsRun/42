/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:39:50 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/23 18:47:31 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

t_list	*ft_list_insert(t_list **begin, t_list *prec, t_list *actu, t_list *new)
{
	if (actu == *begin)
	{
		new->next = *begin;
		*begin = new;
	}
	else
	{
		prec->next = new;
		new->next = actu;
	}
	prec = new;
	return (prec);
}

void	ft_sorted_list_merge(t_list **begin_list1,
	t_list *begin_list2, int (*cmp)())
{
	t_list	*actu;
	t_list	*prec;
	t_list	*next;

	actu = *begin_list1;
	prec = actu;
	while (begin_list2)
	{
		next = begin_list2->next;
		while (actu && cmp(actu->data, begin_list2->data) < 0)
		{
			prec = actu;
			actu = actu->next;
		}
		prec = ft_list_insert(begin_list1, prec, actu, begin_list2);
		begin_list2 = next;
	}
}
