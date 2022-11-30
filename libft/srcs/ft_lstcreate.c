/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:31 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 12:46:54 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcreate(int size, char **data)
{
	t_list	*elem;
	t_list	*nex;
	int		i;

	i = 0;
	elem = NULL;
	if (size <= 0)
		return (NULL);
	while (i < size)
	{
		nex = ft_lstnew((void *)data[i], ft_strlen(data[i]));
		nex->next = elem;
		i++;
		elem = nex;
	}
	return (nex);
}
