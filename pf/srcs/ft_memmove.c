/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:33 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 20:01:24 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (len > 0)
	{
		((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
		len--;
	}
	return (dst);
}
