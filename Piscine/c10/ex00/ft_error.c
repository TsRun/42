/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:14:02 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/14 22:53:09 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	ft_error(int a)
{
	if (a == 0)
		ft_put_error("File name missing.\n");
	if (a == 1)
		ft_put_error("Too many arguments.\n");
	if (a == 2)
		ft_put_error("Cannot read file.\n");
	return (-1);
}
