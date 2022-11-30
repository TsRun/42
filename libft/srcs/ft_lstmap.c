/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:48:20 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 12:27:24 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*elem;
	t_list	*newelem;

	start = NULL;
	elem = NULL;
	while (lst)
	{
		newelem = f(lst);
		if (!newelem)
			return (NULL);
		if (!start)
		{
			start = newelem;
			elem = start;
		}
		else
		{
			elem->next = newelem;
			elem = newelem;
		}
	}
	if (elem)
		elem->next = NULL;
	return (start);
}
