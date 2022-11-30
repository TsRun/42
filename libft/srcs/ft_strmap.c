/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:17:34 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/29 18:19:47 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *str, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = 0;
	res = ft_strnew(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = f(str[i]);
		i++;
	}
	return (res);
}
