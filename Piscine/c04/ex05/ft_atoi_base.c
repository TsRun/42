/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/08 20:13:42 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_instr(char c, char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_checkbase(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| ft_instr(base[i], base, i) != -1)
			return (-1);
		if ((base[i] >= '\t' && base[i] <= '\r') || base[i] == ' ')
			return (-1);
		i++;
	}
	return (1);
}

int	ft_atoi_base2(char *str, char *base, int len)
{
	int	i;
	int	signe;
	int	res;

	res = 0;
	signe = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_instr(str[i], base, len) != -1)
	{
		res = res * len + ft_instr(str[i], base, len);
		i++;
	}
	return (res * signe);
}

int	ft_atoi_base(char *nb, char *base)
{
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	if (ft_checkbase(base) == -1 || len < 2)
		return (0);
	return (ft_atoi_base2(nb, base, len));
}
