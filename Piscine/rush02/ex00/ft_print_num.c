/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:12:10 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 22:50:42 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr2(char *str)
{
	ft_putstr(str);
	ft_putchar(' ');
}

void	ft_print(char *nb, char **dict)
{
	ft_putstr2(dict[nb[-1] - 48]);
	ft_putstr2(dict[28]);
}

int	ft_print_3car(char *nb, int len, char **dict, int i)
{
	if (len == 2)
	{
		if (nb++[0] != '0')
			ft_print(nb, dict);
		if (nb[0] != '0')
			i++;
		len--;
	}
	if (len == 1)
	{
		if (nb[0] == '1')
			ft_putstr2(dict[nb[1] - 38]);
		if (nb[0] == '1')
			len -= 2;
		if (nb[0] != '0')
			i++;
		if (nb[0] != '0' && nb++[0] != '1')
			ft_putstr2(dict[(nb[-1] - 48) + 18]);
		len--;
	}
	if (len == 0 && nb[0] != '0')
		i++;
	if (len == 0 && nb[0] != '0')
		ft_putstr2(dict[nb[0] - 48]);
	return (i);
}

void	ft_print_nb2(char *nb, int len, char **dic)
{
	int	i;

	while (len > 3)
	{
		if (ft_print_3car(nb, (len - 1) % 3, dic, 0) && i != 0)
			ft_putstr2(dic[((len - 1) / 3 - 1) % 3 + 29]);
		i = 1;
		nb += ((len - 1) % 3) + 1;
		len = len - ((len - 1) % 3) - 1;
		if (len % 12 == 0)
		{
			i = 0;
			ft_putstr2(dic[31]);
		}
	}
	ft_print_3car(nb, len - 1, dic, 0);
}

void	ft_print_nb(char *nb, char **dict)
{
	int	len;

	if (!nb)
		return ;
	len = ft_strlen(nb);
	if (nb[0] == '0')
		ft_putstr(dict[0]);
	else
		ft_print_nb2(nb, len, dict);
	ft_putchar('\n');
}
