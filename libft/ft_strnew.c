/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:57:18 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/29 18:00:38 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) malloc(len);
	if (!str)
		return (NULL);
	else
	{
		while (i < len)
		{
			str[i] = '\0';
			i++;
		}
		str[i] = '\0';
		return (str);
	}
}
