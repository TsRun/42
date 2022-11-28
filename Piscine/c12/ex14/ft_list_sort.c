/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:43:55 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/22 17:18:16 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <unistd.h>

t_list	*ft_list_at3(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr && begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

int	ft_list_size3(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

void	ft_swap_struct(t_list **begin, int j)
{
	t_list	*temp;
	t_list	*el1;
	t_list	*el2;
	t_list	*el3;

	if (j == 0)
	{
		el3 = (*begin)->next->next;
		temp = *begin;
		*begin = (*begin)->next;
		(*begin)->next = temp;
		temp->next = el3;
	}
	else
	{
		el1 = ft_list_at3(*begin, j - 1);
		el2 = el1->next;
		el3 = el2->next;
		temp = el3->next;
		el1->next = el3;
		el3->next = el2;
		el2->next = temp;
	}
}

void	ft_list_sort(t_list **begin, int (*cmp)())
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = ft_list_size3(*begin);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (cmp(ft_list_at3(*begin, j)->data,
					ft_list_at3(*begin, j + 1)->data) > 0)
				ft_swap_struct(begin, j);
			j++;
		}
		i++;
	}
}
