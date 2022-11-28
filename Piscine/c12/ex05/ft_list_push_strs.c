/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:31 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/23 12:33:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data);

t_list	*ft_list_push_strs(int size, char **data)
{
	t_list	*elem;
	t_list	*nex;
	int		i;

	i = 0;
	elem = 0;
	if (size <= 0)
		return (0);
	while (i < size)
	{
		nex = ft_create_elem(data[i]);
		nex->next = elem;
		i++;
		elem = nex;
	}
	return (nex);
}
