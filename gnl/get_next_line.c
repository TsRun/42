/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:43 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/05 16:27:39 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
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
	if (!s1)
		return (strndup(s2, len));
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

char	*ft_lastline(char **lst)
{
	char	*tmp;
	int		index;
	char	*temp;

	index = ft_strchr(*lst, '\n');
	if (!lst || !*lst)
	{
		tmp = (char *) malloc(1 * sizeof(char));
		if (!tmp)
			return (NULL);
		tmp[0] = '\0';
	}
	else if (index != -1)
	{
		temp = *lst;
		tmp = strndup(temp, index + 1);
		*lst = strndup(temp + index + 1, ft_strlen(temp) - index - 1);
		free(temp);
	}
	else
	{
		tmp = *lst;
		*lst = NULL;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*lst = NULL;
	ssize_t			i;
	int				index;
	char			*line;

	if (fd < 0 || fd >= 1000)
		return (NULL);
	i = 0;
	if (ft_strchr(lst, '\n') == -1)
		i = read(fd, buf, BUFFER_SIZE);
	line = ft_lastline(&lst);
	if (!line)
		return (NULL);
	if (i < 0)
		return (free(line), NULL);
	while (i > 0 && ft_strchr(buf, '\n') == -1)
	{
		line = ft_realloccat(line, buf, i);
		if (!line)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
	}
	if (i == 0 && ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}
	if (i == 0 && ft_strchr(line, '\n') == -1)
		return (line);
	buf[i] = '\0';
	index = ft_strchr(buf, '\n');
	line = ft_realloccat(line, buf, index + 1);
	lst = ft_realloccat(lst, buf + index + 1, ft_strlen(buf) - index - 1);
	return (line);
}
