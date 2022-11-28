/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:40:32 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 00:18:48 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

t_number	ft_atoi2(char *str)
{
	int			i;
	t_number	res;

	if (ft_strlen(str) > 20
		|| (ft_strlen(str) == 20 && ft_strcmp(str, "18446744073709551615") > 0))
	{
		res.test = -1;
		return (res);
	}
	res.n = 0;
	res.test = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res.n = res.n * 10 + str[i] - 48;
		else
			res.test = 0;
		i++;
	}
	return (res);
}
