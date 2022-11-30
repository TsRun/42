/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:55:33 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/28 21:16:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	int		sens;
	size_t	end;

	i = 0;
	sens = 1;
	end = len;
	if (src < dst)
	{
		sens = -1;
		i = len - 1;
		end = -1;
	}
	while (i != end)
	{
		((char *) dst)[i] = ((char *)src)[i];
		i += sens;
	}
	return (dst);
}
