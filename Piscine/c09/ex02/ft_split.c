/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:41:56 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/12 01:01:16 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc (i + 1);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_instr(char *str, char c)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		j;
	int		nospace;

	i = 0;
	j = 0;
	dest = malloc((ft_strlen(str) / 2 + 1) * sizeof(char *));
	while (str[i])
	{
		nospace = i;
		while (!ft_instr(charset, str[i]) && str[i])
			i++;
		if (nospace != i)
		{
			dest[j] = ft_strndup(str + nospace, i - nospace);
			j++;
		}
		if (str[i])
			i++;
	}
	dest[j] = 0;
	return (dest);
}
