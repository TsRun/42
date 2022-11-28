/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:45:00 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 00:33:40 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_list	*ft_create_elem(char *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->str = data;
	elem->next = 0;
	return (elem);
}

t_list	*str_modif(char **av, int ac)
{
	t_list	*tab;
	t_list	*start;
	int		i;

	i = 0;
	tab = ft_create_elem(av[i]);
	start = tab;
	while (i < ac - 1)
	{
		tab->next = ft_create_elem(av[i + 1]);
		tab = tab->next;
		i++;
	}
	tab = ft_create_elem(0);
	tab->next = 0;
	return (start);
}

t_list	*ft_c2(t_list *list, t_list *elem, t_number *nb, int n)
{
	if (n == -1)
		return (0);
	nb->n += n;
	elem->next = list->next;
	return (elem);
}

int	ft_c_option(t_list *list, char *name)
{
	t_list		*elem;
	t_number	*nb;
	int			oct;
	int			n;

	elem = list;
	nb = malloc(sizeof (t_number));
	nb->n = 0;
	while (list)
	{
		n = ft_cmp(list->str, name);
		if (n)
		{
			list = ft_c2(list, elem, nb, n);
			if (!list)
				return (-1);
		}
		elem = list;
		list = list->next;
	}
	oct = nb->n;
	free(nb);
	return (oct);
}
