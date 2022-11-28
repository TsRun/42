/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:01:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 22:52:09 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_realloc_cat(char *s1, char *s2, int lens2)
{
	int		lens1;
	char	*s3;
	int		j;

	lens1 = ft_strlen(s1);
	s3 = malloc (lens1 + lens2 + 1);
	j = 0;
	while (j < lens1)
	{
		s3[j] = s1[j];
		j++;
	}
	j = 0;
	while (j < lens2)
	{
		s3[lens1 + j] = s2[j];
		j++;
	}
	s3[lens1 + lens2] = '\0';
	free(s1);
	return (s3);
}

char	*ft_read_file(int fd)
{
	char	reader[50];
	int		len;
	char	*str;
	int		readed;

	len = read(fd, reader, 50);
	readed = 0;
	if (len < 0)
		return (0);
	str = malloc(1);
	str[0] = 0;
	while (len > 0)
	{
		str = ft_realloc_cat(str, reader, len);
		readed += len;
		len = read(fd, reader, 50);
	}
	while (str[readed - 1] == '\n')
	{
		str[readed - 1] = 0;
		readed--;
	}
	return (str);
}
