/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jauffret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 20:41:27 by jauffret          #+#    #+#             */
/*   Updated: 2022/11/02 22:23:12 by jauffret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char(char c)
{
	write(1, &c, 1);
}

void	comma(int nb, int n)
{
	if (n == 1 && nb == 9)
		return ;
	if (n == 2 && nb == 89)
		return ;
	if (n == 3 && nb == 789)
		return ;
	if (n == 4 && nb == 6789)
		return ;
	if (n == 5 && nb == 56789)
		return ;
	if (n == 6 && nb == 456789)
		return ;
	if (n == 7 && nb == 3456789)
		return ;
	if (n == 8 && nb == 23456789)
		return ;
	if (n == 9 && nb == 123456789)
		return ;
	print_char(',');
	print_char(' ');
}

void	ft_putnbr(int nb, int n)
{
	int	div;
	int	nn;

	div = 1;
	nn = n;
	while (nn > 1)
	{
		div = div * 10;
		nn = nn - 1;
	}
	while (div > 0)
	{
		print_char(((nb / div) % 10) + 48);
		if (div < 10)
		{
			comma(nb, n);
		}
		div /= 10;
	}
}

void	recursive_while(int a, int n, int b, int s)
{
	if (a != 256565452)
	{
		b = b * 10;
		b = b + a;
		a = (b % 10) + 1;
	}
	else
		a = 0;
	if (n > 0)
	{	
		while (a < 10)
		{
			recursive_while(a, n - 1, b, s);
			a++;
		}
	}
	else
	{
		if (b != 0)
			ft_putnbr(b, s);
	}
	return ;
}

void	ft_print_combn(int n)
{
	int	a;

	a = 256565452;
	recursive_while(a, n, 0, n);
}
