/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:43:27 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/03 18:48:21 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEXA "0123456789abcdef"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char j)
{
	if (!(j >= 32 && j <= 126))
		return (0);
	return (1);
}

void	ft_puthexa(unsigned char c)
{
	ft_putchar('\\');
	ft_putchar(HEXA[c / 16]);
	ft_putchar(HEXA[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_is_printable(str[i])))
			ft_puthexa(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
