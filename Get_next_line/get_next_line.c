/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:43 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/03 15:57:23 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	size_t i;

	 i = 0;
	 while (str[i])
		 i++;
	 return (i);
}

char	*ft_realloccat(char *s1, char *s2, int len)
{
	size_t	len_s1;
	char	*res;
	int		i;

	i = 0;
	len_s1 = ft_strlen(s1);
	res = (char *) malloc(len + len_s1 + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		res[len_s1 + i] = s2[i];
		i++;
	}
	free(s1);
	res[len_s1 + i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE];
	static char	*t_list = NULL;
	size_t		i;
	int			index;
	char		*line;

	i = (size_t)read(fd, buf, BUFFER_SIZE);
	line = (char *) malloc(1);
	if (!(line) || i < 0)
		return (NULL);
	line[0] = '\0';
	if (lstline)
		line = ft_realloccat(line, lstline, ft_strlen(lstline));
	while (i > 0 && ft_strchr(buf, '\n') == -1)
	{
		line = ft_realloccat(line, buf, i);
		if (!line)
			return (NULL);
		i = (size_t)read(fd, buf, BUFFER_SIZE);
	}
	if (i == 0 && ft_strlen(line) == 0)
		return (NULL);
	if (i == 0)
		return (line);
	index = ft_strchr(buf, '\n');
	line = ft_realloccat(line, buf, index + 1);
	lstline = strndup(buf + index + 1, i - index - 1);
	return (line);
}
