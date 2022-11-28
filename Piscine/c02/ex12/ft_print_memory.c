/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:57:57 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/06 23:38:17 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define HEXA "0123456789abcdef"

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(unsigned long long adr, int i)
{
	if (i)
	{
		ft_print_hexa(adr / 16, i - 1);
		ft_putchar(HEXA[adr % 16]);
		if (i == 15)
			write(1, ": ", 2);
	}
	else
		ft_putchar(HEXA[adr % 16]);
}

void	ft_print_str(char *str, unsigned int size)
{
	unsigned int		i;
	unsigned long long	c;

	i = 0;
	while (i <= size)
	{
		c = (unsigned long long) str[i];
		ft_print_hexa(c, 1);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	i = 5 * (15 - size) / 2 + (size + 1) % 2;
	write(1, "                                           ", i);
	i = 0;
	while (i <= size)
	{
		c = str[i];
		if (c < 32 || c > 126)
			ft_putchar('.');
		else
			ft_putchar((unsigned char) c);
		i++;
	}
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char				*c;
	unsigned long long	adr;
	unsigned int		i;

	i = 0;
	c = (char *) addr;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			adr = (unsigned long long) c;
			ft_print_hexa(adr, 15);
		}
		if (i % 16 == 15 || i == size - 1)
		{
			ft_print_str(c, i);
			if (i == size - 1)
				return (addr);
			i = -1;
			size -= 16;
			c += 16;
		}
		i++;
	}
	return (addr);
}
