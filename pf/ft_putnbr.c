/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:02:23 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/07 19:29:23 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_putnbr_recur(unsigned int n, int aff)
{
	int	cpt;

	cpt = 0;
	if (n < 10)
		cpt += ft_putchar((char)(n + '0'), aff);
	else
	{
		cpt += ft_putnbr_recur(n / 10, aff);
		cpt += ft_putchar((char)(n % 10 + '0'), aff);
	}
	return (cpt);
}

static int ft_putnnbr(unsigned int n, int aff, int c)
{
	int	cpt;

	cpt = 0;
	if (c <= 0 && n == 0)
		return (0);
	if (c <= 1 && n < 10)
		cpt += ft_putchar((char)(n + '0'), aff);
	else
	{
		cpt += ft_putnnbr(n / 10, aff, c - 1);
		cpt += ft_putchar((char)(n % 10 + '0'), aff);
	}
	return (cpt);
}

int	ft_putnbr(int n, int aff, int opt)
{
	int	cpt;

	cpt = 0;
	if (n < 0)
	{
		cpt += ft_putchar('-', aff);
		n *= -1;
	}
	if (opt <= -1)
		cpt += ft_putnbr_recur((unsigned int) n, aff);
	else
		cpt += ft_putnnbr((unsigned int) n, aff, opt);
	return (cpt);
}
