/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:40:04 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/07 13:36:35 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char const *str, int aff, int size)
{
	size_t	len;

	if (!str)
	{
		len = 6;
		if (size != -1)
			len = ft_min(size, 6);
		if (aff)
			write(1, "(null)", len);
	}
	else
	{
		len = ft_strlen(str);
		if (size != -1)
			len = ft_min(len, size);
		if (aff)
			write(1, str, len);
	}
	return (len);
}
