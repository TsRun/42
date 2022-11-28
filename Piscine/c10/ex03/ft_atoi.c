/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:40:32 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/17 16:11:00 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_number	ft_atoi2(char *str)
{
	int			i;
	t_number	res;

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
