/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:54:41 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/05 11:49:36 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, int y, int lenght, int height)
{
	if (y == 0 || y == height - 1)
	{
		if ((x == 0 || x == lenght - 1)
			&& (x + y == 0 || x + y == lenght + height - 2))
			ft_putchar('/');
		else if (x == 0 || x == lenght - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else
	{
		if (x == 0 || x == lenght - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	rush(int lenght, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < lenght)
		{
			ft_print(x, y, lenght, height);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
