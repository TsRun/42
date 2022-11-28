/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:57:57 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 20:28:10 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#define HEXA "0123456789abcdef"

void	ft_put_hexa(unsigned char adr, int i)
{
	if (i > 1)
	{
		ft_put_hexa(adr / 16, i - 1);
		ft_putchar(HEXA[adr % 16]);
	}
	else
		ft_putchar(HEXA[adr % 16]);
}

void	ft_put_space(int n)
{
	while (n > 0)
	{
		ft_putchar(' ');
		n--;
	}
}

void	ft_putsuite(char *str, int size)
{
	int	i;

	i = 0;
	ft_putchar('|');
	while (i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("|\n");
}

void	ft_print_norm2(int nb, t_string *str, int k)
{
	int		i;
	char	*str2;

	if (str->size == 0)
	{
		if (k)
			return (ft_put_hexa(k, 8), ft_putstr("\n"));
		else
			return ;
	}
	str2 = which_str(str, k);
	if (k != 0 && ft_strncmp(str2, which_str(str, k - 16), str->size))
	{
		if (str->djvu != 1)
			ft_putstr("*\n");
		str->djvu = 1;
		return ;
	}
	i = 0;
	if (nb > 1)
		ft_print_norm2(nb - 1, str, k);
	ft_put_hexa(k, 8);
	while (i < str->size)
	{
		ft_putchar(' ');
		if (i % 8 == 0)
			ft_putchar(' ');
		ft_put_hexa(str2[i], 2);
		i++;
	}
	str->djvu = 0;
	if (str->size > 0)
		ft_put_space((16 - str->size) * 3 + 2 + (str->size <= 8));
	if (str->size > 0)
		ft_putsuite(str2, str->size);
	else
		ft_putstr("\n");
}

void	ft_print_norm(int nb, t_string *str, int k)
{
	int		i;
	char	*str2;

	str2 = which_str(str, k);
	if (nb > 0)
		ft_print_norm2(nb, str, k);
	if (nb > 0)
		return ;
	if (str->size == 0)
	{
		if (k)
			return (ft_put_hexa(k, 7), ft_putstr("\n"));
		else
			return ;
	}
	str2 = which_str(str, k);
	if (k != 0 && ft_strncmp(str2, which_str(str, k - 16), str->size))
	{
		if (str->djvu != 1)
			ft_putstr("*\n");
		str->djvu = 1;
		return ;
	}
	i = 0;
	if (nb > 1)
		ft_print_norm2(nb - 1, str, k);
	ft_put_hexa(k, 7);
	while (i < str->size)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		if (i % 2 == 0 && i == str->size - 1)
			ft_put_hexa(0, 2);
		else if (i % 2)
			ft_put_hexa(str2[i - 1], 2);
		else
			ft_put_hexa(str2[i + 1], 2);
		i++;
	}
	if (str->size % 2)
	{
		ft_put_hexa(str2[i - 1], 2);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_putstr("  ");
		i++;
	}
	str->djvu = 0;
	ft_putchar('\n');
}
