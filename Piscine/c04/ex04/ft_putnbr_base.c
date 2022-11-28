/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/06 20:53:49 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_instr(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || ft_instr(base[i], base + i + 1))
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr2(unsigned int n, char *base, unsigned int len)
{
	if (n < len)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr2(n / len, base, len);
		ft_putchar(base[n % len]);
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	unsigned int	n;
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_checkbase(base) || len < 2)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	n = nb;
	ft_putnbr2(n, base, len);
}
