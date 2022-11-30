/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:03:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/30 11:35:53 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ctype.h"

void	ft_free(void *yo, size_t yop)
{
	(void)yop;
	if (yo)
		free(yo);
}

int	main(int ac, char **av)
{
	t_list	*elem;
	if (ac < 2)
		return (0);
	char	*s1 = ft_strdup(av[1]);
	elem = ft_lstnew((void *)s1, ft_strlen(s1));
	ft_putendl((char *)elem->content);
	ft_putnbr((int) elem->content_size);
	ft_lstdelone(&elem, &ft_free);
}
