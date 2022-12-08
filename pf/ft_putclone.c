/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 07:41:26 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:15:50 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadr2(void *nb, t_opt opt)
{
	int	cpt;

	cpt = ft_putadr(nb, 0);
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_putadr(nb, 1);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}

int	ft_puthexa2(unsigned long long nb, int maj, t_opt opt)
{
	int	cpt;

	if (opt.opt_zero == 1 && opt.size_opt == -1)
		opt.size_opt = opt.size;
	cpt = 0;
	cpt = ft_puthexa(nb, maj, 0, opt.size_opt);
	if (opt.is_ox && nb != 0)
	{
		if (maj)
			cpt += ft_putstr("0X", 1, -1);
		else
			cpt += ft_putstr("0x", 1, -1);
	}
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_puthexa(nb, maj, 1, opt.size_opt);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}

int	ft_putunsigned2(unsigned int nb, t_opt opt)
{
	int	cpt;

	if (opt.opt_zero == 1 && opt.size_opt == -1)
		opt.size_opt = opt.size - (nb < 0);
	cpt = ft_putunsigned(nb, 0, opt.size_opt);
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_putunsigned(nb, 1, opt.size_opt);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}

int	ft_putnbr2(int nb, t_opt opt)
{
	int	cpt;

	if (opt.opt_zero == 1 && opt.size_opt == -1)
		opt.size_opt = opt.size - (nb < 0);
	cpt = ft_putnbr(nb, 0, opt.size_opt);
	if (opt.space && nb >= 0)
		cpt += ft_putchar(opt.space, 1);
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_putnbr(nb, 1, opt.size_opt);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}

int	ft_putstr2(const char *c, t_opt opt)
{
	int	cpt;

	cpt = ft_putstr(c, 0, opt.size_opt);
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_putstr(c, 1, opt.size_opt);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}

int	ft_putchar2(char c, t_opt opt)
{
	int	cpt;

	cpt = ft_putchar(c, 0);
	if (opt.opt_right == 0)
		ft_putnchar(opt.size - cpt, ' ');
	ft_putchar(c, 1);
	if (opt.opt_right)
		ft_putnchar(opt.size - cpt, ' ');
	if (opt.size > cpt)
		return (opt.size);
	else
		return (cpt);
}
