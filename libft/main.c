/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:03:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/28 21:51:36 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	size_t	size;
	char	*s1;
	char	*s2;
	int		c;
	int		size_str;
	size_t	i;

	if (ac <= 5)
		return (0);
	i = 0;
	s1 = strdup(av[1]);
	c = atoi(av[5]);
	s2 = strdup(av[1]);
	size = atoi(av[3]);
	size_str = atoi(av[4]);
	printf("%p\n", memchr((void *)s1, c, size));
	printf("%p\n", ft_memchr((void *)s1, c, size));
	while (i < (size_t) size_str)
	{
		printf("%lc : %lc\n", s1[i], s2[i]);
		i++;
	}
}
