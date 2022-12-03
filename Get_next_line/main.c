/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:35:05 by maserrie          #+#    #+#             */
/*   Updated: 2022/12/02 17:15:44 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	**str;

	str = malloc(sizeof(char *));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("%s\n", "met un bon nom connard");
		return(0);
	}
	while (get_next_line(fd, str) == 1)
	{
		printf("%s\n", *str);
		free(*str);
	}
	printf("%s\n", *str);
	free(*str);
	(void)ac;
}
