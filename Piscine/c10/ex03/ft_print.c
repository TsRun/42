/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:27:19 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 00:36:18 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putnstr(char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
		i++;
	write(1, str, n);
}

int	ft_cmp(char *s1, char *name)
{
	int		i;
	int		c;

	i = 1;
	c = 0;
	if (s1[0] != '-' || s1[1] == '\0')
		return (0);
	while (s1[i] == 'C')
	{
		c++;
		i++;
	}
	if (s1[i] != '\0')
	{
		ft_error2(0, 0, s1 + i, name);
		return (-1);
	}
	return (c);
}

void	ft_putstrtab(char **av, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putstr(av[i]);
		ft_putstr("\n");
	}
}

int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_put_struct(t_list *list)
{
	while (list)
	{
		ft_putstr(list->str);
		ft_putstr("\n");
		list = list->next;
	}
}
