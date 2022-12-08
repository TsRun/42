/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:23 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/08 03:16:24 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int	ft_max(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

t_opt	ft_option(char const **str, int j)
{
	t_opt	opt;
	size_t	i;

	i = j;
	opt.size = -1;
	opt.opt_zero = 0;
	opt.opt_right = 0;
	opt.opt = '\0';
	opt.size_opt = -1;
	opt.space = 0;
	opt.is_ox = 0;
	if ((*str)[i] == '#')
		opt.is_ox = (*str)++[i];
	while ((*str)[i] == ' ' || (*str)[i] == '+')
		opt.space = (*str)++[i];
	while ((*str)[i] == '-' || (*str)[i] == '0')
	{
		if ((*str)[i] == '-')
			opt.opt_right = 1;
		else
			opt.opt_zero = 1;
		(*str)++;
	}
	opt.size = ft_atoi(*str + i);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		(*str)++;
	if ((*str)[i] == '.')
		opt.size_opt = ft_atoi(++(*str) + i);
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		(*str)++;
	if (!(*str)[i] || !ft_strchr("\%xdiXucps", (*str)[i]))
		return (opt);
	opt.opt = (*str)[i];
	return (opt);
}

void	ft_putnchar(int n, char c)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}


int	ft_printf(char const *s, ...)
{
	size_t	i;
	va_list	ap;
	int		cpt;
	t_opt	opt;

	cpt = 0;
	va_start(ap, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (!s[i])
				break;
			opt = ft_option(&s, i);
			if (s[i] == '%')
				cpt += ft_putchar2('%', opt);
			else if (s[i] == 'i' || s[i] == 'd')
				cpt += ft_putnbr2((int)va_arg(ap, int), opt);
			else if (s[i] == 's')
				cpt += ft_putstr2((const char *)va_arg(ap, const char *), opt);
			else if (s[i] == 'c')
				cpt += ft_putchar2((char)va_arg(ap, int), opt);
			else if (s[i] == 'u')
				cpt += ft_putunsigned2((unsigned int)va_arg(ap, unsigned int), opt);
			else if (s[i] == 'X' || s[i] == 'x')
				cpt += ft_puthexa2((unsigned long long)va_arg(ap, unsigned int), s[i] == 'X', opt);
			else if (s[i] == 'p')
				cpt += ft_putadr2((void *)va_arg(ap, void *), opt);
			else
				break;
		}
		else
			cpt += ft_putchar(s[i], 1);
		i++;
	}
	va_end(ap);
	return (cpt);
}
