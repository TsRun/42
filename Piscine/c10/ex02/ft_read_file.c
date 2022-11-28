/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:01:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 19:38:48 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_swap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

unsigned long long	size_file(char *file_name, char *name)
{
	int		i;
	int		len;
	int		fd;
	char	str[16000];

	i = 0;
	len = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error(file_name, 0, name));
	while (len)
	{
		len = read(fd, str, 16000);
		if (len < 0)
			return (ft_error(file_name, 1, name));
		i += len;
	}
	if (close(fd) == -1)
		return (ft_error(file_name, 0, name));
	return (i);
}

void	ft_read_file(char *file_name, t_lol oct, t_number *i, char *name)
{
	char				*str;
	unsigned long long	size;
	int					fd;

	size = size_file (file_name, name);
	if (size == 0)
		return ;
	str = malloc (size + 1);
	fd = open(file_name, O_RDONLY);
	read(fd, str, size);
	str[size] = 0;
	if (i->test)
		ft_put_header(file_name, *i);
	i->n = i->n + 1;
	if (oct < size)
		ft_putnstr(str + size - oct, oct);
	else
		ft_putnstr(str, size);
	free(str);
}

char	*ft_realloc_cat(char *s1, char *s2, int len)
{
	int		i;
	char	*s3;
	int		j;

	i = ft_strlen(s1);
	s3 = malloc (i + len + 2);
	j = 0;
	while (j < i)
	{
		s3[j] = s1[j];
		j++;
	}
	i = 0;
	while (i < len)
	{
		s3[i + j] = s2[i];
		i++;
	}
	s3[i + j] = '\0';
	free(s1);
	return (s3);
}

void	ft_read_input(unsigned long long oct)
{
	char				str[16000];
	unsigned long long	len;
	char				*res;
	int					red;

	if (oct == 0)
		return ;
	red = read(0, str, 16000);
	res = malloc(1);
	res[0] = '\0';
	len = 0;
	while (red > 0)
	{
		res = ft_realloc_cat(res, str, red);
		len += red;
		red = read(0, str, 16000);
	}
	if (oct < len)
		ft_putstr(res + len - oct);
	else
		ft_putstr(res);
	free(res);
	return ;
}
