/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 22:31:09 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/09 19:48:06 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_itoa_base(int nb, char *base, char *dest);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

int	ft_atoi_base(char *str, char *base, int len)
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

char	*ft_convert_base(char *nb, char *base_from, char *base_to)
{
	unsigned int	len1;
	unsigned int	len2;
	unsigned int	lennb;
	char			*dest;

	lennb = ft_strlen(nb);
	len1 = ft_strlen(base_from);
	len2 = ft_strlen(base_to);
	if (ft_checkbase(base_from) == -1 || len1 < 2
		|| len2 < 2 || ft_checkbase(base_to) == -1)
		return (0);
	dest = malloc (lennb * len2);
	dest = ft_itoa_base(ft_atoi_base(nb, base_from, len1), base_to, dest);
	return (dest);
}
