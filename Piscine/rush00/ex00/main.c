/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 10:22:16 by maserrie          #+#    #+#             */
/*   Updated: 2022/11/05 12:07:48 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	rush(int lenght, int height);

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	res;

	i = 0;
	signe = 1;
	res = 0;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (signe * res);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc > 2)
	{
		a = ft_atoi(argv[1]);
		b = ft_atoi(argv[2]);
	}
	else
	{
		a = 1;
		b = 1;
	}
	if (a < 1 || b < 1)
	{
		ft_putstr("Tu peux mettre un nombre strictement positif");
		ft_putstr(" stp Gero (si c'est pas Gero j'ai le seum)\n");
	}
	else
		rush(a, b);
	return (0);
}
