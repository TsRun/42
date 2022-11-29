/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:03:37 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/29 01:34:00 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	char	*s1;
	char	*s2;
	size_t	size;

	size = atoi(av[3]);
	s1 = ft_strdup(av[1]);
	s2 = ft_strdup(av[1]);
	s1 = strncat(s1, av[2], size);
	s2 = ft_strncat(s2, av[2], size);
	(void) size;
	printf("%s\n", s1);
	printf("%s\n", s2);
	free(s1);
	free(s2);
}
