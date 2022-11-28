/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:27:25 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/20 23:16:32 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*is_number(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		str++;
	if (str[i] == '+')
		str++;
	while (str[i] == '0' && str[i + 1])
	{
		str++;
		k++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		k++;
	}
	if (str[i] == '-')
		return ((void) ft_error(1, ""), (char *) 0);
	if (str[i] || k == 0)
		return ((void) ft_error(2, ""), (char *) 0);
	return (str);
}

int	main(int ac, char **av)
{
	char	*str;
	char	**dict;
	int		fd;
	char	*file_name;
	char	*num;

	file_name = "numbers.dict";
	num = av[ac - 1];
	if (ac == 1)
		num = ft_read_file(0);
	if (ac == 3)
		file_name = av[1];
	if (ac > 3)
		return (ft_error(4, ""));
	fd = open(file_name, O_RDONLY);
	str = ft_read_file(fd);
	if (!str)
		return (ft_error(3, file_name));
	dict = ft_parse(ft_split(str, "\n"));
	if (!dict)
		return ((void)free(str), -1);
	ft_print_nb(is_number(num), dict);
	free(str);
	ft_freetab(dict);
	return (0);
}
