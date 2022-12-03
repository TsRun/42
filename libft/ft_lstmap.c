/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:48:20 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 21:40:31 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *elem), void (*del)(void *))
{
	t_list	*start;
	t_list	*elem;
	t_list	*newelem;

	start = NULL;
	elem = NULL;
	while (lst)
	{
		newelem = ft_lstnew(f(lst->content));
		if (!newelem)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
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
		lst = lst->next;
	}
	if (elem)
		elem->next = NULL;
	return (start);
}
