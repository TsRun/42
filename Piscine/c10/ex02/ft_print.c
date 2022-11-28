/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 01:27:19 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/17 00:41:43 by maserrie         ###   ########.fr       */
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

int	ft_cmp(char *s1)
{
	int		i;
	char	*s2;

	s2 = "-c";
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == 0)
		return (2);
	else if (s2[i] == 0)
		return (1);
	return (0);
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
