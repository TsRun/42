/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:02:23 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 01:04:51 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void ft_putnbr_recur(unsigned int n)
{
	if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr_recur(n / 10);
		ft_putchar((char)(n % 10 + '0'));
	}
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putnbr_recur((unsigned int) n);
}
