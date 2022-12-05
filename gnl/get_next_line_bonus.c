/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:03:43 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/05 16:30:33 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	res[len_s1 + i] = '\0';
	free(s1);
	return (res);
}

t_list	*ft_lstnew(char	*str, int fd)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->lstline = str;
	elem->fd = fd;
	elem->next = NULL;
	return (elem);
}

t_list	**ft_lstadd(t_list **lst, char *str, int fd)
{
	t_list	**list;
	t_list	*tmp;
	t_list	*new;

	new = ft_lstnew(strndup(str, ft_strlen(str)), fd);
	if (!new)
		return (NULL);
	if (!lst)
	{
		list = (t_list **)malloc(sizeof (t_list *));
		if (!list)
			return (NULL);
		*list = new;
		return (list);
	}
	tmp = *lst;
	*lst = new;
	new->next = tmp;
	return (lst);
}

t_list	*ft_inlst(t_list *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_lstdel(t_list **lst, t_list *elem)
{
	t_list	*last;
	t_list	*next;

	if (!lst)
		return ;
	next = *lst;
	while (next && next != elem)
	{
		last = next;
		next = next->next;
	}
	if (!next)
	{
		free(elem);
		return ;
	}
	if (next == *lst)
	{
		*lst = next->next;
		free(elem);
		return ;
	}
	last->next = next->next;
	free(elem);
}

char	*ft_lastline(t_list **lst, int fd)
{
	t_list	*elem;
	int		index;
	char	*tmp[2];

	if (!lst || !ft_inlst(*lst, fd))
	{
		tmp[0] = malloc(1);
		if (!tmp[0])
			return (NULL);
		tmp[0][0] = '\0';
		return (tmp[0]);
	}
	elem = ft_inlst(*lst, fd);
	index = ft_strchr(elem->lstline, '\n') + 1;
	tmp[1] = elem->lstline;
	if (index == 0)
		return (ft_lstdel(lst, elem), tmp[1]);
	tmp[0] = strndup(tmp[1], index);
	elem->lstline = strndup(tmp[1] + index, ft_strlen(tmp[1]) - index);
	free(tmp[1]);
	return (tmp[0]);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	static t_list	**lst = NULL;
	ssize_t			i;
	int				index;
	char			*line;

	if (fd == -1 || fd >= 1000)
		return (NULL);
	i = 0;
	if (!lst || !ft_inlst(*lst, fd) || ft_strchr(ft_inlst(*lst, fd)->lstline, '\n') == -1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
	}
	if (i < 0)
		return (NULL);
	line = ft_lastline(lst, fd);
	if (!line)
		return (NULL);
	while (i > 0 && ft_strchr(buf, '\n') == -1)
	{
		line = ft_realloccat(line, buf, i);
		if (!line)
			return (NULL);
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
	}
	if (i == 0 && ft_strlen(line) == 0)
	{
		if (lst && !*lst)
		{
			free(lst);
			lst = NULL;
		}
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') != -1)
		return (line);
	if (i == 0 && ft_strchr(buf, '\n') == -1)
		return (line);
	index = ft_strchr(buf, '\n');
	line = ft_realloccat(line, buf, index + 1);
	lst = ft_lstadd(lst, buf + index + 1, fd);
	return (line);
}
