/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:34:10 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/08 00:13:40 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long long nb, int maj, int aff, int c)
{
	char	*hex;
	int		cpt;

	cpt = 0;
	if (c == 0 && nb == 0)
		return (0);
	if (maj == 0)
		hex = HEXA;
	else
		hex = HEXA_MAJ;
	if (nb >= 16 || c > 1)
	{
		cpt += ft_puthexa(nb / 16, maj, aff, c - 1);
		cpt += ft_putchar(hex[nb % 16], aff);
	}
	else
		cpt += ft_putchar(hex[nb % 16], aff);
	return (cpt);
}

int	ft_putadr(void *adr, int aff)
{
	int	cpt;

	cpt = ft_putstr("0x", aff, 4);
	cpt += ft_puthexa((unsigned long long)adr, 0, aff, -1);
	return (cpt);
}
