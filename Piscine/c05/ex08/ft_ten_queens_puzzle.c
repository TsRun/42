/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 03:46:51 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/08 18:42:23 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_attack(int y, int tab[10][2], int x)
{
	int	i;

	i = 0;
	while (tab[i][1] != -1 && i <= 10)
	{
		if (y == tab[i][1] || x - y == tab[i][0] - tab[i][1]
			|| x + y == tab[i][0] + tab[i][1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_puttab(int tab[10][2], int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		ft_putchar(tab[i][1] + '0');
		i++;
	}
}

void	ft_recur_queens(int c, int tab[10][2], int *n)
{
	int	i;

	i = 0;
	if (c >= 10)
	{
		ft_puttab(tab, 10);
		ft_putchar('\n');
		*n = *n + 1;
		return ;
	}
	while (i < 10)
	{
		if (ft_attack(i, tab, c))
		{
			tab[c][1] = i;
			ft_recur_queens(c + 1, tab, n);
			tab[c][1] = -1;
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10][2];
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < 10)
	{
		tab[i][0] = i;
		tab[i][1] = -1;
		i++;
	}
	ft_recur_queens(0, tab, &k);
	return (k);
}
