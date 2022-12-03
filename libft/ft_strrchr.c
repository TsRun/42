/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:01:11 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 22:10:38 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			res = ((char *)(s + i));
		i++;
	}
	if ((unsigned char)c == 0)
		res = ((char *)(s + i));
	return (res);
}
