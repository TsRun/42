/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 20:52:01 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 20:57:03 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (!lst)
		return ;
	elem = *lst;
	if (!elem)
		*lst = new;
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = new;
		new->next = NULL;
	}
}
