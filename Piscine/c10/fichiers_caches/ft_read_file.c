/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:01:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/19 00:43:10 by maserrie         ###   ########.fr       */
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

char	*which_str(t_string	*str, int i)
{
	if (i % 32 == 0)
		return (str->string);
	else
		return (str->prec);
}

int	ft_read_file(char *file_name, int nb, t_string *str, int *size)
{
	int		fd;
	int		len;
	char	s2[16];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_error(file_name, 0, str->prog));
	len = read(fd, s2, 16 - str->size);
	if (len < 0)
		return (ft_error(file_name, 1, str->prog));
	ft_strncat(which_str(str, *size), s2, str->size, len);
	len += str->size;
	str->size = len;
	while (len % 16 == 0 && len > 0)
	{
		ft_print_norm(nb, str, *size);
		*size = *size + 16;
		len = read(fd, which_str(str, *size), 16);
	}
	str->size = len;
	return (0);
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

void	ft_read_input(int nb, t_string *str)
{
	int		len;
	int		k;
	char	s1[32];
	char	s2[16];
	int		size;

	len = read(0, s2, 16);
	s1[0] = 0;
	k = 0;
	size = 0;
	while (len > 0)
	{
		ft_strncat(s1, s2, size, len);
		size += len;
		if (size >= 16)
		{
			ft_strncpy(s1, which_str(str, k), 16);
			str_16(s1, size);
			str->size = 16;
			ft_print_norm(nb, str, k);
			size -= 16;
			k += 16;
		}
		len = read(0, s2, 16);
	}
	str->size = size;
	if (size)
	{
		ft_strncpy(s1, which_str(str, k), str->size);
		ft_print_norm(nb, str, k);
	}
	k += size;
	str->size = 0;
	if (k)
		ft_print_norm(nb, str, k);
}
