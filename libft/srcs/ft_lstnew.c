/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:23:24 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 01:26:18 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *) malloc (sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = (void *)content;
	if (!content)
		elem->content_size = 0;
	else
		elem->content_size = content_size;
	elem->next = NULL;
	return (elem);
}
