/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:52:29 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/11 10:02:50 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*res;
	int		len;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	res = (char *) malloc(len + 2 + ft_strlen(sep) * size);
	res[0] = '\0';
	i = 0;
	while (i < size)
	{
		res = ft_strcat(res, strs[i]);
		if (i != size - 1)
			res = ft_strcat(res, sep);
		i++;
	}
	return (res);
}
