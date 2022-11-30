/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:28:26 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/29 17:56:14 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t i)
{
	void	*str;

	str = malloc(i);
	if (!str)
		return (NULL);
	else
	{
		ft_bzero(str, i);
		return (str);
	}
}
