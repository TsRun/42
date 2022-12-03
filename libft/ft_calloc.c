/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:47 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 18:41:05 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t len, size_t size)
{
	void	*mem;
	size_t	temp;

	temp = len * size;
	if (temp / len != size)
		return (NULL);
	if (len == 0 || size == 0)
		return (malloc(0));
	mem = malloc(temp);
	if (!mem)
		return (NULL);
	bzero(mem, temp);
	return (mem);
}
