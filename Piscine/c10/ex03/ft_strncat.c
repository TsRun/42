/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:50:25 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/18 15:43:40 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_strncat(char *s1, char *s2, int len1, int len)
{
	int	j;

	j = 0;
	while (j < len)
	{
		s1[len1 + j] = s2[j];
		j++;
	}
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}

void	str_16(char *str, int n)
{
	int	i;

	i = 0;
	while (i + 16 < n)
	{
		str[i] = str[i + 16];
		i++;
	}
}
