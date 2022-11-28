/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 09:54:41 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/05 11:55:57 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_print(int x, int y, int lenght, int height)
{
	if (y == 0 || y == height - 1)
	{
		if (x == 0)
			ft_putchar('A');
		else if (x == lenght - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (x == 0 || x == lenght - 1)
			ft_putchar('B');
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
