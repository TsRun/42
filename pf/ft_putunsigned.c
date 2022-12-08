/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:40:52 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/07 19:32:23 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int nb, int aff, int opt)
{
	int	cpt;

	cpt = 0;
	if (opt == 0 && nb == 0)
		return (0);
	if (nb >= 10 || opt > 1)
	{
		cpt += ft_putnbr((int)(nb / 10), aff, opt - 1);
		cpt += ft_putchar(nb % 10 + 48, aff);
	}
	else
		cpt += ft_putchar(nb % 10 + 48, aff);
	return (cpt);
}
