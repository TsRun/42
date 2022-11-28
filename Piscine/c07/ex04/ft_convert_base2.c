/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/09 19:36:34 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_addchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

void	ft_putnbr2(unsigned int n, char *base, unsigned int len, char *dest)
{
	if (n < len)
		dest = ft_addchar(dest, base[n]);
	else
	{
		ft_putnbr2(n / len, base, len, dest);
		dest = ft_addchar(dest, base[n % len]);
	}
}

char	*ft_itoa_base(int nb, char *base, char *dest)
{
	unsigned int	n;
	unsigned int	len;

	len = 0;
	while (base[len])
		len++;
	if (nb < 0)
	{
		dest = ft_addchar(dest, '-');
		nb *= -1;
	}
	n = nb;
	ft_putnbr2(n, base, len, dest);
	return (dest);
}
